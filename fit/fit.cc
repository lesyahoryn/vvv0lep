#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TF1.h"
#include "TVirtualFitter.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"

// #define EXPO

#ifdef EXPO
#define FITFUNC expo
#define FITFUNCERR expo_err
#else
#define FITFUNC expo2
#define FITFUNCERR expo2_err
#endif

double expo(const double* params, double x)
{
    return TMath::Exp(params[0]+params[1]*x);
}

double expo_d1(const double* params, double x)
{
    return TMath::Exp(params[0]+params[1]*x);
}

double expo_d2(const double* params, double x)
{
    return x*TMath::Exp(params[0]+params[1]*x);
}

double expo_err(const double* params, const double* cov, double x)
{
    return sqrt(
        pow(expo_d1(params, x), 2) * cov[0] +
        pow(expo_d2(params, x), 2) * cov[3] +
        2 * (expo_d1(params, x) * expo_d2(params, x)) * cov[1]
        );
}

//============================================================

double expo2(const double* params, double x)
{
    return TMath::Exp(params[0]+params[1]*x+params[2]*x*x);
}

double expo2_d1(const double* params, double x)
{
    return TMath::Exp(params[0]+params[1]*x+params[2]*x*x);
}

double expo2_d2(const double* params, double x)
{
    return x*TMath::Exp(params[0]+params[1]*x+params[2]*x*x);
}

double expo2_d3(const double* params, double x)
{
    return x*x*TMath::Exp(params[0]+params[1]*x+params[2]*x*x);
}

double expo2_err(const double* params, const double* cov, double x)
{
    return sqrt(
        pow(expo2_d1(params, x), 2) * cov[0] +
        pow(expo2_d2(params, x), 2) * cov[4] +
        pow(expo2_d3(params, x), 2) * cov[8] +
        2 * (expo2_d1(params, x) * expo2_d2(params, x)) * cov[1] +
        2 * (expo2_d1(params, x) * expo2_d3(params, x)) * cov[2] +
        2 * (expo2_d2(params, x) * expo2_d3(params, x)) * cov[5]
        );
}

//============================================================

double expo3(const double* params, double x)
{
    return TMath::Exp(params[0]+params[1]*x+params[2]*TMath::Log(x));
}

double expo3_d1(const double* params, double x)
{
    return TMath::Exp(params[0]+params[1]*x+params[2]*TMath::Log(x));
}

double expo3_d2(const double* params, double x)
{
    return x*TMath::Exp(params[0]+params[1]*x+params[2]*TMath::Log(x));
}

double expo3_d3(const double* params, double x)
{
    return TMath::Log(x)*TMath::Exp(params[0]+params[1]*x+params[2]*TMath::Log(x));
}

double expo3_err(const double* params, const double* cov, double x)
{
    return sqrt(
        pow(expo3_d1(params, x), 2) * cov[0] +
        pow(expo3_d2(params, x), 2) * cov[4] +
        pow(expo3_d3(params, x), 2) * cov[8] +
        2 * (expo3_d1(params, x) * expo3_d2(params, x)) * cov[1] +
        2 * (expo3_d1(params, x) * expo3_d3(params, x)) * cov[2] +
        2 * (expo3_d2(params, x) * expo3_d3(params, x)) * cov[5]
        );
}

//============================================================

double func(const double* params, double x, int fitfunc)
{
    if (fitfunc == 0)
        return expo(params, x);
    else
        return expo2(params, x);
}

double func_err(const double* params, const double* cov, double x, int fitfunc)
{
    if (fitfunc == 0)
        return expo_err(params, cov, x);
    else
        return expo2_err(params, cov, x);
}

//============================================================

int run_fit(TString filename, TString histname, TString newhist, double min, double max, int fitfunc)
{
    gROOT->SetBatch(kTRUE);

    // Open the file
    TFile* f = new TFile(filename);

    TString hist = histname;
    TH1F* ho = (TH1F*) f->Get(hist.Data())->Clone();
    TH1F* h = (TH1F*) f->Get(hist.Data())->Clone();
    TH1F* h2 = (TH1F*) h->Clone();

    TCanvas* c = new TCanvas();

    TString funcdefn;
    if (fitfunc == 0)
        funcdefn = "expo(0)";
    else
        funcdefn = "TMath::Exp([0]+[1]*x+[2]*x^2)";

    TF1* g = new TF1("graph", funcdefn.Data(), min, max);
    TF1* g2 = new TF1("graph2", funcdefn.Data(), 0, 3500);
    g->SetLineWidth(4);
    g->SetLineColor(4);

    // Perform fit
    TFitResultPtr fr = h->Fit("graph", "RVS");
    fr->Print("V");

    // Get results and copy to another object
    const double* params = g->GetParameters();
    const double* errors = g->GetParErrors();
    g2->SetParameters(params);
    g2->SetParErrors(errors);

    // Get covariance matrix
    const double* cov = fr->GetCovarianceMatrix().GetMatrixArray();

    h->SetLineColor(1);
    h->SetMarkerStyle(20);
    h->SetMarkerSize(0.5);
    h2->SetLineColor(1);
    h2->SetMarkerStyle(20);
    h2->SetMarkerSize(0.5);
    h->Draw("ep");
    g2->Draw("same");
    c->SetLogy();

    c->SaveAs(TString::Format("%s_fitresult.pdf", histname.Data()));

    //-------==========--------------==========--------------==========--------------==========-------
    //-------==========--------------==========--------------==========--------------==========-------
    //-------==========--------------==========--------------==========--------------==========-------

    TH1F* ratio = (TH1F*) ho->Clone();

    for (unsigned int ibin = 1; ibin <= ratio->GetNbinsX(); ibin++)
    {
        double y = ratio->GetBinContent(ibin);
        double yerr = ratio->GetBinError(ibin);
        double bc = ratio->GetBinCenter(ibin);
        double eval = func(params, bc, fitfunc);
        double evalerr = func_err(params, cov, bc, fitfunc);
        double evalfracerr = evalerr / eval;
        double yfracerr = yerr / y;
        double new_over_old = y != 0 ? eval / y : 0;
        double new_over_old_err = y != 0 ? sqrt(evalfracerr*evalfracerr + yfracerr*yfracerr) * new_over_old : 0;
        ratio->SetBinContent(ibin, new_over_old);
        ratio->SetBinError(ibin, new_over_old_err);
    }

    ratio->SetMinimum(0);
    ratio->SetMaximum(2);
    ratio->Draw();

    c->SetLogy(0);
    c->SaveAs(TString::Format("%s_ratio.pdf", histname.Data()));
    c->SetLogy(1);

    //-------==========--------------==========--------------==========--------------==========-------
    //-------==========--------------==========--------------==========--------------==========-------
    //-------==========--------------==========--------------==========--------------==========-------

    TH1F* hvbo = (TH1F*) f->Get(newhist.Data());
    hvbo->Print("all");

    TString outputfilename = filename.ReplaceAll("QCD", "QCDFIT");
    TFile* of = new TFile(outputfilename, "UPDATE");

    TH1F* newh = (TH1F*) hvbo->Clone();
    newh->Reset();

    double fbw = ho->GetBinWidth(1);

    for (int ibin = 1; ibin <= hvbo->GetNbinsX(); ++ibin)
    {
        double bl = hvbo->GetBinLowEdge(ibin);
        double bw = hvbo->GetBinWidth(ibin);
        std::cout <<  " bl: " << bl <<  " bw: " << bw <<  std::endl;
        int nslice = int(bw) / int(fbw);
        if (ibin == hvbo->GetNbinsX())
            nslice = 1000;
        double residual = int(bw) % int(fbw);
        if (residual != 0)
        {
            std::cout <<  " filename: " << filename <<  " histname: " << histname <<  " newhist: " << newhist <<  std::endl;
            std::cout << "ERROR! bin width is not a multiplicative of fine bin width!" << std::endl;
            exit(1);
        }
        double ysum = 0;
        double yerrsqsum = 0;
        double prev_y = 99999;
        for (unsigned islice = 0; islice < nslice; ++islice)
        {
            double x = bl + fbw / 2  + fbw * islice;
            double y = func(params, x, fitfunc);
            double yerr = func_err(params, cov, x, fitfunc);
            // std::cout <<  " x: " << x <<  " y: " << y <<  " yerr: " << yerr <<  " bw: " << bw <<  " fbw: " << fbw <<  " ysum: " << ysum <<  " sqrt(yerrsqsum): " << sqrt(yerrsqsum) <<  std::endl;
            ysum += y;
            yerrsqsum += yerr*yerr;
            if (prev_y < y) // if the function starts to increase again then stop it's non-sensical
                break;
            prev_y = y;
        }
        double yerrsum = sqrt(yerrsqsum);
        newh->SetBinContent(ibin, ysum);
        newh->SetBinError(ibin, yerrsum);
    }

    TString hist_write_name = TString::Format("%s_FitHist", ho->GetName());
    TH1F* hotowrite = (TH1F*) ho->Clone();
    hotowrite->SetTitle(hist_write_name);
    hotowrite->SetName(hist_write_name);

    hotowrite->Write(TString::Format("%s_FitHist", ho->GetName()), TObject::kOverwrite);
    newh->Write(newh->GetName(), TObject::kOverwrite);
    g2->Write(TString::Format("%s_TF1", newh->GetName()), TObject::kOverwrite);

    newh->Print("all");

    hvbo->SetMarkerStyle(20);
    hvbo->SetLineColor(1);
    hvbo->SetMarkerColor(1);
    hvbo->Draw("ep");

    hvbo->SetMinimum(0.001);

    newh->SetMarkerStyle(20);
    newh->SetLineColor(2);
    newh->SetMarkerColor(2);
    newh->SetMarkerSize(0.5);
    newh->Draw("epsame");

    c->SaveAs(TString::Format("%s_extrapolation.pdf", histname.Data()));

    of->Close();

    return 0;
}

int main(int argc, char** argv)
{
    run_fit("../output/VVV0TreeV7/Run2/merged/QCD.root", "ZL2FJA__HTJFit", "ZL2FJA__HTJ_binned", 1100, 2500, 1);
    run_fit("../output/VVV0TreeV7/Run2/merged/QCD.root", "ZL2FJE__HTJFit", "ZL2FJE__HTJ_binned", 1100, 2500, 1);
    run_fit("../output/VVV0TreeV7/Run2/merged/QCD.root", "ZL3FJA__SR1SumPtFJ", "ZL3FJA__SR1SumPtFJ", 1100, 2500, 1);
    run_fit("../output/VVV0TreeV7/Run2/merged/QCD.root", "ZL3FJE__SR1SumPtFJ", "ZL3FJE__SR1SumPtFJ", 1100, 2500, 1);
    return 0;
}

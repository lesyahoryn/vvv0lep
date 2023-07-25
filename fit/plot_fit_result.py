#!/bin/env python3

import ROOT as r
r.gROOT.SetBatch(True)

import math

import plottery_wrapper as p
from plottery import plottery as plt

def draw(histname, fithistname):
    f = r.TFile("../output/VVV0TreeV7/Run2/merged/QCDFIT.root")
    f.ls()
    th1 = f.Get(f"{fithistname}_FitHist").Clone()
    th1.Print("all")
    th1_extrapolated = f.Get(f"{histname}").Clone()
    th1.Print("all")
    tf1 = f.Get(f"{histname}_TF1")

    a = math.exp(tf1.GetParameter(0))
    b = math.log(a / th1.GetBinWidth(1))
    tf1.SetParameter(0, b)
    tf1.SetLineColor(4)
    tf1.SetRange(0, 90000)

    data = th1.Clone()

    for i in range(th1.GetNbinsX()):
        data.SetBinContent(i+1, tf1.Eval(data.GetBinCenter(i+1)))
        data.SetBinError(i+1, math.sqrt(tf1.Eval(data.GetBinCenter(i+1))*th1.GetBinWidth(1))/th1.GetBinWidth(1))

    p.divide_by_bin_width([th1, th1_extrapolated])

    persist = []
    c = p.plot_hist(
            bgs=[th1],
            sigs=[th1_extrapolated],
            data=data,
            legend_labels=["QCD Data Driven"],
            colors=[4003],
            options={
                "output_name": f"fitresult/{histname}_result.pdf",
                "yaxis_log": True,
                "legend_scalex": 2.,
                "xaxis_label": "H_{T,Fat-Jet} [GeV]",
                "print_yield": True,
                "ratio_range": [0., 2.],
                },
            _persist=persist,
            )
    c.cd(1)
    tf1.Draw("same")
    c.SaveAs(f"fitresult/{histname}_result.pdf")
    c.SaveAs(f"fitresult/{histname}_result.png")

if __name__ == "__main__":

    draw("ZL3FJE__SR1SumPtFJ", "ZL3FJE__SR1SumPtFJ")
    draw("ZL3FJA__SR1SumPtFJ", "ZL3FJA__SR1SumPtFJ")
    draw("ZL2FJE__HTJ_binned", "ZL2FJE__HTJFit")
    draw("ZL2FJA__HTJ_binned", "ZL2FJA__HTJFit")

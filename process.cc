#include "VVV0Tree.h"
#include "rooutil.h"
#include "cxxopts.h"

using json = nlohmann::json;

class AnalysisConfig {

public:

    // TString that holds the input file list (comma separated)
    TString input_file_list_tstring;

    // TString that holds the name of the TTree to open for each input files
    TString input_tree_name;

    // TString that holds the name of the syst variation
    TString syst_name;

    // Output TFile
    TFile* output_tfile;

    // Number of events to loop over
    int n_events;

    // Jobs to split (if this number is positive, then we will skip certain number of events)
    // If there are N events, and was asked to split 2 ways, then depending on job_index, it will run over first half or latter half
    int nsplit_jobs;

    // Job index (assuming nsplit_jobs is set, the job_index determine where to loop over)
    int job_index;

    // Debug boolean
    bool debug;

    // TChain that holds the input TTree's
    TChain* events_tchain;

    // Custom Looper object to facilitate looping over many files
    RooUtil::Looper<VVV0Tree> looper;

    // Custom Cutflow framework
    RooUtil::Cutflow cutflow;

    // Custom Histograms object compatible with RooUtil::Cutflow framework
    RooUtil::Histograms histograms;

};

AnalysisConfig ana;

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

//********************************************************************************
//
// 1. Parsing options
//
//********************************************************************************

    // cxxopts is just a tool to parse argc, and argv easily

    // Grand option setting
    cxxopts::Options options("\n  $ doAnalysis",  "\n         **********************\n         *                    *\n         *       Looper       *\n         *                    *\n         **********************\n");

    // Read the options
    options.add_options()
        ("J,json"        , "json job config",                                                                                                                         cxxopts::value<std::string>())
        ("i,input"       , "Comma separated input file list OR if just a directory is provided it will glob all in the directory BUT must end with '/' for the path", cxxopts::value<std::string>())
        ("t,tree"        , "Name of the tree in the root file to open and loop over"                                             , cxxopts::value<std::string>())
        ("s,syst"        , "Syst variation name"                                                                                 , cxxopts::value<std::string>())
        ("o,output"      , "Output file name"                                                                                    , cxxopts::value<std::string>())
        ("n,nevents"     , "N events to loop over"                                                                               , cxxopts::value<int>()->default_value("-1"))
        ("j,nsplit_jobs" , "Enable splitting jobs by N blocks (--job_index must be set)"                                         , cxxopts::value<int>())
        ("I,job_index"   , "job_index of split jobs (--nsplit_jobs must be set. index starts from 0. i.e. 0, 1, 2, 3, etc...)"   , cxxopts::value<int>())
        ("d,debug"       , "Run debug job. i.e. overrides output option to 'debug.root' and 'recreate's the file.")
        ("h,help"        , "Print help")
        ;

    auto result = options.parse(argc, argv);

    // NOTE: When an option was provided (e.g. -i or --input), then the result.count("<option name>") is more than 0
    // Therefore, the option can be parsed easily by asking the condition if (result.count("<option name>");
    // That's how the several options are parsed below

    //_______________________________________________________________________________
    // --help
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --input
    if (result.count("input"))
    {
        ana.input_file_list_tstring = result["input"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input list is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --json
    if (result.count("json"))
    {
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Json file not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --tree
    if (result.count("tree"))
    {
        ana.input_tree_name = result["tree"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input tree name is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --syst
    if (result.count("syst"))
    {
        ana.syst_name = result["syst"].as<std::string>();
    }
    else
    {
        ana.syst_name = "";
    }

    //_______________________________________________________________________________
    // --debug
    if (result.count("debug"))
    {
        ana.output_tfile = new TFile("debug.root", "recreate");
    }
    else
    {
        //_______________________________________________________________________________
        // --output
        if (result.count("output"))
        {
            ana.output_tfile = new TFile(result["output"].as<std::string>().c_str(), "recreate");
            // if (not ana.output_tfile->IsOpen())
            // {
            //     std::cout << options.help() << std::endl;
            //     std::cout << "ERROR: output already exists! provide new output name or delete old file. OUTPUTFILE=" << result["output"].as<std::string>() << std::endl;
            //     exit(1);
            // }
        }
        else
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: Output file name is not provided! Check your arguments" << std::endl;
            exit(1);
        }
    }

    //_______________________________________________________________________________
    // --nevents
    ana.n_events = result["nevents"].as<int>();

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("nsplit_jobs"))
    {
        ana.nsplit_jobs = result["nsplit_jobs"].as<int>();
        if (ana.nsplit_jobs <= 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --nsplit_jobs" << ana.nsplit_jobs << " has zero or negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.nsplit_jobs = -1;
    }

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("job_index"))
    {
        ana.job_index = result["job_index"].as<int>();
        if (ana.job_index < 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index" << ana.job_index << " has negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.job_index = -1;
    }


    // Sanity check for split jobs (if one is set the other must be set too)
    if (result.count("job_index") or result.count("nsplit_jobs"))
    {
        // If one is not provided then throw error
        if ( not (result.count("job_index") and result.count("nsplit_jobs")))
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index and --nsplit_jobs must be set at the same time!" << std::endl;
            exit(1);
        }
        // If it is set then check for sanity
        else
        {
            if (ana.job_index >= ana.nsplit_jobs)
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: --job_index >= --nsplit_jobs ! This does not make sense..." << std::endl;
                exit(1);
            }
        }
    }

    //
    // Printing out the option settings overview
    //
    std::cout <<  "=========================================================" << std::endl;
    std::cout <<  " Setting of the analysis job based on provided arguments " << std::endl;
    std::cout <<  "---------------------------------------------------------" << std::endl;
    std::cout <<  " ana.input_file_list_tstring: " << ana.input_file_list_tstring <<  std::endl;
    std::cout <<  " ana.output_tfile: " << ana.output_tfile->GetName() <<  std::endl;
    std::cout <<  " ana.n_events: " << ana.n_events <<  std::endl;
    std::cout <<  " ana.nsplit_jobs: " << ana.nsplit_jobs <<  std::endl;
    std::cout <<  " ana.job_index: " << ana.job_index <<  std::endl;
    std::cout <<  "=========================================================" << std::endl;

//********************************************************************************
//
// 2. Opening input baby files
//
//********************************************************************************

    // Create the TChain that holds the TTree's of the baby ntuples
    ana.events_tchain = RooUtil::FileUtil::createTChain(ana.input_tree_name, ana.input_file_list_tstring);

    // Create a Looper object to loop over input files
    // the "www" object is defined in the wwwtree.h/cc
    // This is an instance which helps read variables in the WWW baby TTree
    // It is a giant wrapper that facilitates reading TBranch values.
    // e.g. if there is a TBranch named "lep_pt" which is a std::vector<float> then, one can access the branch via
    //
    //    std::vector<float> lep_pt = www.lep_pt();
    //
    // and no need for "SetBranchAddress" and declaring variable shenanigans necessary
    // This is a standard thing SNT does pretty much every looper we use
    ana.looper.init(ana.events_tchain, &vvv, ana.n_events);

//********************************************************************************
//
// Interlude... notes on RooUtil framework
//
//********************************************************************************

    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    // Quick tutorial on RooUtil::Cutflow object cut tree formation
    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    //
    // The RooUtil::Cutflow object facilitates creating a tree structure of cuts
    //
    // To add cuts to each node of the tree with cuts defined, use "addCut" or "addCutToLastActiveCut"
    // The "addCut" or "addCutToLastActiveCut" accepts three argument, <name>, and two lambda's that define the cut selection, and the weight to apply to that cut stage
    //
    // e.g. To create following cut-tree structure one does
    //
    //             (Root) <--- Always exists as soon as RooUtil::Cutflow object is created. But this is basically hidden underneath and users do not have to care
    //                |
    //            CutWeight
    //            |       |
    //     CutPreSel1    CutPreSel2
    //       |                  |
    //     CutSel1           CutSel2
    //
    //
    //   code:
    //
    //      // Create the object (Root node is created as soon as the instance is created)
    //      RooUtil::Cutflow cutflow;
    //
    //      cutflow.addCut("CutWeight"                 , <lambda> , <lambda>); // CutWeight is added below "Root"-node
    //      cutflow.addCutToLastActiveCut("CutPresel1" , <lambda> , <lambda>); // The last "active" cut is "CutWeight" since I just added that. So "CutPresel1" is added below "CutWeight"
    //      cutflow.addCutToLastActiveCut("CutSel1"    , <lambda> , <lambda>); // The last "active" cut is "CutPresel1" since I just added that. So "CutSel1" is added below "CutPresel1"
    //
    //      cutflow.getCut("CutWeight"); // By "getting" the cut object, this makes the "CutWeight" the last "active" cut.
    //      cutflow.addCutToLastActiveCut("CutPresel2" , <lambda> , <lambda>); // The last "active" cut is "CutWeight" since I "getCut" on it. So "CutPresel2" is added below "CutWeight"
    //      cutflow.addCutToLastActiveCut("CutSel2"    , <lambda> , <lambda>); // The last "active" cut is "CutPresel2" since I just added that. So "CutSel2" is added below "CutPresel1"
    //
    // (Side note: "UNITY" lambda is defined in the framework to just return 1. This so that use don't have to type [&]() {return 1;} so many times.)
    //
    // Once the cutflow is formed, create cutflow histograms can be created by calling RooUtil::Cutflow::bookCutflows())
    // This function looks through the terminating nodes of the tree structured cut tree. and creates a histogram that will fill the yields
    // For the example above, there are two terminationg nodes, "CutSel1", and "CutSel2"
    // So in this case Root::Cutflow::bookCutflows() will create two histograms. (Actually four histograms.)
    //
    //  - TH1F* type object :  CutSel1_cutflow (4 bins, with first bin labeled "Root", second bin labeled "CutWeight", third bin labeled "CutPreSel1", fourth bin labeled "CutSel1")
    //  - TH1F* type object :  CutSel2_cutflow (...)
    //  - TH1F* type object :  CutSel1_rawcutflow (...)
    //  - TH1F* type object :  CutSel2_rawcutflow (...)
    //                                ^
    //                                |
    // NOTE: There is only one underscore "_" between <CutName>_cutflow or <CutName>_rawcutflow
    //
    // And later in the loop when RooUtil::Cutflow::fill() function is called, the tree structure will be traversed through and the appropriate yields will be filled into the histograms
    //
    // After running the loop check for the histograms in the output root file

    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    // Quick tutorial on RooUtil::Histograms object
    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    //
    // The RooUtil::Histograms object facilitates book keeping histogram definitions
    // And in conjunction with RooUtil::Cutflow object, one can book same histograms across different cut stages easily without copy pasting codes many times by hand.
    //
    // The histogram addition happens in two steps.
    // 1. Defining histograms
    // 2. Booking histograms to cuts
    //
    // Histograms are defined via following functions
    //
    //      RooUtil::Histograms::addHistogram       : Typical 1D histogram (TH1F*) "Fill()" called once per event
    //      RooUtil::Histograms::addVecHistogram    : Typical 1D histogram (TH1F*) "Fill()" called multiple times per event
    //      RooUtil::Histograms::add2DHistogram     : Typical 2D histogram (TH2F*) "Fill()" called once per event
    //      RooUtil::Histograms::add2DVecHistogram  : Typical 2D histogram (TH2F*) "Fill()" called multiple times per event
    // e.g.
    //
    //    RooUtil::Histograms histograms;
    //    histograms.addHistogram   ("MllSS"    , 180 , 0. , 300. , [&]() { return www.MllSS()  ; }); // The lambda returns float
    //    histograms.addVecHistogram("AllLepPt" , 180 , 0. , 300. , [&]() { return www.lep_pt() ; }); // The lambda returns vector<float>
    //
    // The addVecHistogram will have lambda to return vector<float> and it will loop over the values and call TH1F::Fill() for each item
    //
    // To book histograms to cuts one uses
    //
    //      RooUtil::Cutflow::bookHistogramsForCut()
    //      RooUtil::Cutflow::bookHistogramsForCutAndBelow()
    //      RooUtil::Cutflow::bookHistogramsForCutAndAbove()
    //      RooUtil::Cutflow::bookHistogramsForEndCuts()
    //
    // e.g. Given a tree like the following, we can book histograms to various cuts as we want
    //
    //              Root
    //                |
    //            CutWeight
    //            |       |
    //     CutPreSel1    CutPreSel2
    //       |                  |
    //     CutSel1           CutSel2
    //
    // For example,
    //
    //    1. book a set of histograms to one cut:
    //
    //       cutflow.bookHistogramsForCut(histograms, "CutPreSel2")
    //
    //    2. book a set of histograms to a cut and below
    //
    //       cutflow.bookHistogramsForCutAndBelow(histograms, "CutWeight") // will book a set of histograms to CutWeight, CutPreSel1, CutPreSel2, CutSel1, and CutSel2
    //
    //    3. book a set of histograms to a cut and above (... useless...?)
    //
    //       cutflow.bookHistogramsForCutAndAbove(histograms, "CutPreSel2") // will book a set of histograms to CutPreSel2, CutWeight (nothing happens to Root node)
    //
    //    4. book a set of histograms to a terminating nodes
    //
    //       cutflow.bookHistogramsForEndCuts(histograms) // will book a set of histograms to CutSel1 and CutSel2
    //
    // The naming convention of the booked histograms are as follows
    //
    //   cutflow.bookHistogramsForCut(histograms, "CutSel1");
    //
    //  - TH1F* type object : CutSel1__MllSS;
    //  - TH1F* type object : CutSel1__AllLepPt;
    //                               ^^
    //                               ||
    // NOTE: There are two underscores "__" between <CutName>__<HistogramName>
    //
    // And later in the loop when RooUtil::CutName::fill() function is called, the tree structure will be traversed through and the appropriate histograms will be filled with appropriate variables
    // After running the loop check for the histograms in the output root file

    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);

    // various information on the sample is saved in a json format
    std::ifstream jj(result["json"].as<std::string>()); //
    json j;
    jj >> j;
    int is_data = j["is_data"];
    int is_sig = j["is_sig"];
    int is_eft = j["is_eft"];
    float lumi = j["lumi"];
    float xsec = j["xsec"];
    float sum_genWeight = j["sum_genWeight"];
    TString process = j["process"];
    int eft_idx = 0;
    int year = j["year"];

    #include "lambda.h"

    //===============================================================================================================================================================
    // Applying weights
    ana.cutflow.addCut("Base",
                       [&, is_sig, is_eft]()
                       {
                           if (is_eft)
                           {
                               return LHEReweightingWeight().size() != 0;
                           }
                           else
                           {
                               return true;
                           }
                       },
                       [&, is_data, is_sig, is_eft, eft_idx, lumi, xsec, sum_genWeight]()
                       {
                           if (is_data)
                           {
                               return 1.f;
                           }
                           else
                           {
                               float wgt = genWeight() * lumi * xsec * 1000.0 / sum_genWeight;
                               if (is_eft)
                               {
                                   if (LHEReweightingWeight().size() != 0)
                                       return LHEReweightingWeight()[eft_idx] * wgt;
                                   else
                                       return 0.f;
                               }
                               else
                               {
                                   return wgt;
                               }
                           }
                       } );

    //===============================================================================================================================================================
    // One lepton region
    ana.cutflow.getCut("Base");
    ana.cutflow.addCutToLastActiveCut("OL", [&]() { return is1Lep(); }, UNITY);
    ana.cutflow.addCutToLastActiveCut("OL1FJ", [&]() { return NFJ() == 1; }, UNITY);
    // True Fat-jet's (W fat-jets from top)
    ana.cutflow.getCut("OL1FJ");
    ana.cutflow.addCutToLastActiveCut("OLTB", [&]() { return NbTight() >= 1; }, UNITY);
    ana.cutflow.getCut("OLTB");
    ana.cutflow.addCutToLastActiveCut("OLElTB", [&]() { return abs(LepFlav()) == 11; }, UNITY);
    ana.cutflow.getCut("OLTB");
    ana.cutflow.addCutToLastActiveCut("OLMuTB", [&]() { return abs(LepFlav()) == 13; }, UNITY);
    // Fake Fat-jet's
    ana.cutflow.getCut("OL1FJ");
    ana.cutflow.addCutToLastActiveCut("OLNB", [&]() { return NoORNbTight() == 0; }, UNITY);
    ana.cutflow.getCut("OLNB");
    ana.cutflow.addCutToLastActiveCut("OLElNB", [&]() { return abs(LepFlav()) == 11; }, UNITY);
    ana.cutflow.getCut("OLNB");
    ana.cutflow.addCutToLastActiveCut("OLMuNB", [&]() { return abs(LepFlav()) == 13; }, UNITY);
    // For each regions add regions with pt bins and flavors
    vector<TString> regions = {"OLTB", "OLElTB", "OLMuTB", "OLNB", "OLElNB", "OLMuNB"};
    vector<float> ptbins = {200, 250, 300, 350, 400, 450, 500, 600, 800, 1000, 1300};
    vector<TString> flavor_names = {"Top", "W", "QB", "Q", "B", "Other"};
    for (unsigned int ibin = 0; ibin < ptbins.size(); ++ibin)
    {
        int pt_lower_bound = ptbins[ibin];
        int pt_upper_bound = ibin != ptbins.size() - 1 ? ptbins[ibin + 1] : 13600;
        for (auto& region : regions)
        {
            TString kinematic_bin_name = TString::Format("%sPtLo%dHi%d", region.Data(), pt_lower_bound, pt_upper_bound);
            ana.cutflow.getCut(region);
            ana.cutflow.addCutToLastActiveCut(
                kinematic_bin_name,
                [&, pt_lower_bound, pt_upper_bound]()
                {
                    float pt = FJ0().pt();
                    return (pt > pt_lower_bound and pt <= pt_upper_bound);
                }, UNITY);
            // Split by flavors
            for (unsigned int iflavor = 0; iflavor < flavor_names.size(); ++iflavor)
            {
                ana.cutflow.getCut(kinematic_bin_name);
                TString name = TString::Format("%s%s", kinematic_bin_name.Data(), flavor_names[iflavor].Data());
                ana.cutflow.addCutToLastActiveCut(name, [&, iflavor]() { return fjcateg() == int(iflavor); }, UNITY);
            }
        }
    }

    //===============================================================================================================================================================
    // Zero lepton region
    ana.cutflow.getCut("Base");
    ana.cutflow.addCutToLastActiveCut("ZL", [&]() { return is0Lep(); }, UNITY);

    //===============================================================================================================================================================
    // Zero lepton + two fat-jet region
    ana.cutflow.getCut("ZL");
    ana.cutflow.addCutToLastActiveCut("ZL2FJ", [&]() { return NFJ() == 2; }, UNITY);

    //===============================================================================================================================================================
    // Zero lepton + three fat-jet region
    ana.cutflow.getCut("ZL");
    ana.cutflow.addCutToLastActiveCut("ZL3FJ", [&]() { return NFJ() >= 3; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("ZL3FJPresel", [&]() { return SumPtFJ() > 1250 and FJ0().pt() > 500.; }, [&, process]() { if (process.Contains("QCD")) return 2.05391728656f; else return 1.f; });
    ana.cutflow.addCutToLastActiveCut("ZL3FJM150"  , [&]() { return FJ0().mass() < 150. and FJ1().mass() < 150. and FJ2().mass() < 150.; }, UNITY);
    ana.cutflow.getCut("ZL3FJM150");
    ana.cutflow.addCutToLastActiveCut("ZL3FJA", [&]() { return is_inside_3d() and vmd_reg_3d() == 8; }, BLIND);
    ana.cutflow.getCut("ZL3FJM150");
    ana.cutflow.addCutToLastActiveCut("ZL3FJB", [&]() { return is_outside_3d() and vmd_reg_3d() == 8; }, UNITY);
    ana.cutflow.getCut("ZL3FJM150");
    ana.cutflow.addCutToLastActiveCut("ZL3FJC", [&]() { return is_inside_3d() and vmd_reg_3d() != 8; }, UNITY);
    ana.cutflow.getCut("ZL3FJM150");
    ana.cutflow.addCutToLastActiveCut("ZL3FJD", [&]() { return is_outside_3d() and vmd_reg_3d() != 8; }, UNITY);
    ana.cutflow.getCut("ZL3FJM150");
    ana.cutflow.addCutToLastActiveCut("ZL3FJE", [&]() { return is_shell_3d() and vmd_reg_3d() == 8; }, UNITY);
    ana.cutflow.getCut("ZL3FJM150");
    ana.cutflow.addCutToLastActiveCut("ZL3FJF", [&]() { return is_shell_3d() and vmd_reg_3d() != 8; }, UNITY);
    for (unsigned int ieft = 0; ieft < 91; ++ieft)
    {
        // The various EFT regions
        ana.cutflow.getCut("ZL3FJA");
        ana.cutflow.addCutToLastActiveCut(TString::Format("ZL3FJAEFTIDX%d", ieft), UNITY, [&, is_eft, ieft]() { if (is_eft) return LHEReweightingWeight()[ieft] / LHEReweightingWeight()[0]; else return 1.f; });
    }

    // Print cut structure
    ana.cutflow.printCuts();

    // Histogram utility object that is used to define the histograms
    RooUtil::Histograms histograms_FJ0;
    histograms_FJ0.addHistogram("Pt0"    , 180 , 0       , 3000   , [&]() { return FJ0().pt(); } );
    histograms_FJ0.addHistogram("Eta0"   , 180 , -5      , 5      , [&]() { return FJ0().eta(); } );
    histograms_FJ0.addHistogram("Phi0"   , 180 , -3.1416 , 3.1416 , [&]() { return FJ0().phi(); } );
    histograms_FJ0.addHistogram("Mass0"  , 180 , 0       , 250    , [&]() { return FJ0().mass(); } );
    histograms_FJ0.addHistogram("VMD0"   , 180 , 0       , 1      , [&]() { return VMD0(); } );
    histograms_FJ0.addHistogram("NQGen0" , 7   , 0       , 7      , [&]() { return NQGen0(); } );
    histograms_FJ0.addHistogram("NBGen0" , 7   , 0       , 7      , [&]() { return NBGen0(); } );
    histograms_FJ0.addHistogram("NLGen0" , 7   , 0       , 7      , [&]() { return NLGen0(); } );
    RooUtil::Histograms histograms_FJ1;
    histograms_FJ1.addHistogram("Pt1"    , 180 , 0       , 2500   , [&]() { return FJ1().pt(); } );
    histograms_FJ1.addHistogram("Eta1"   , 180 , -5      , 5      , [&]() { return FJ1().eta(); } );
    histograms_FJ1.addHistogram("Phi1"   , 180 , -3.1416 , 3.1416 , [&]() { return FJ1().phi(); } );
    histograms_FJ1.addHistogram("Mass1"  , 180 , 0       , 250    , [&]() { return FJ1().mass(); } );
    histograms_FJ1.addHistogram("VMD1"   , 180 , 0       , 1      , [&]() { return VMD1(); } );
    histograms_FJ1.addHistogram("NQGen1" , 7   , 0       , 7      , [&]() { return NQGen1(); } );
    histograms_FJ1.addHistogram("NBGen1" , 7   , 0       , 7      , [&]() { return NBGen1(); } );
    histograms_FJ1.addHistogram("NLGen1" , 7   , 0       , 7      , [&]() { return NLGen1(); } );
    RooUtil::Histograms histograms_FJ2;
    histograms_FJ2.addHistogram("Pt2"    , 180 , 0       , 1500   , [&]() { return FJ2().pt(); } );
    histograms_FJ2.addHistogram("Eta2"   , 180 , -5      , 5      , [&]() { return FJ2().eta(); } );
    histograms_FJ2.addHistogram("Phi2"   , 180 , -3.1416 , 3.1416 , [&]() { return FJ2().phi(); } );
    histograms_FJ2.addHistogram("Mass2"  , 180 , 0       , 250    , [&]() { return FJ2().mass(); } );
    histograms_FJ2.addHistogram("VMD2"   , 180 , 0       , 1      , [&]() { return VMD2(); } );
    histograms_FJ2.addHistogram("NQGen2" , 7   , 0       , 7      , [&]() { return NQGen2(); } );
    histograms_FJ2.addHistogram("NBGen2" , 7   , 0       , 7      , [&]() { return NBGen2(); } );
    histograms_FJ2.addHistogram("NLGen2" , 7   , 0       , 7      , [&]() { return NLGen2(); } );
    RooUtil::Histograms histograms_event;
    histograms_event.addHistogram("NbLoose"      , 7   , 0 , 7    , [&]() { return NbLoose(); } );
    histograms_event.addHistogram("NbMedium"     , 7   , 0 , 7    , [&]() { return NbMedium(); } );
    histograms_event.addHistogram("NbTight"      , 7   , 0 , 7    , [&]() { return NbTight(); } );
    histograms_event.addHistogram("NoORNbLoose"  , 7   , 0 , 7    , [&]() { return NoORNbLoose(); } );
    histograms_event.addHistogram("NoORNbMedium" , 7   , 0 , 7    , [&]() { return NoORNbMedium(); } );
    histograms_event.addHistogram("NoORNbTight"  , 7   , 0 , 7    , [&]() { return NoORNbTight(); } );
    histograms_event.addHistogram("HT"           , 180 , 0 , 5000 , [&]() { return HT(); } );
    histograms_event.addHistogram("HTFJ"         , 180 , 0 , 5000 , [&]() { return HTFJ(); } );
    histograms_event.addHistogram("HTJ"          , 180 , 0 , 5000 , [&]() { return HTJ(); } );
    histograms_event.addHistogram("SumPtFJ"      , 180 , 0 , 5000 , [&]() { return SumPtFJ(); } );
    histograms_event.addHistogram("SumPtJ"       , 180 , 0 , 5000 , [&]() { return SumPtJ(); } );
    histograms_event.addHistogram("MET"          , 180 , 0 , 1000 , [&]() { return MET().pt(); } );
    RooUtil::Histograms histograms_onelep;
    histograms_onelep.addHistogram("LPt"     , 180 , 0       , 1000   , [&]() { return Lep().pt(); } );
    histograms_onelep.addHistogram("LEta"    , 180 , -5      , 5      , [&]() { return Lep().eta(); } );
    histograms_onelep.addHistogram("LPhi"    , 180 , -3.1416 , 3.1416 , [&]() { return Lep().phi(); } );
    histograms_onelep.addHistogram("LepFlav" , 30  , -15     , 15     , [&]() { return LepFlav(); } );
    RooUtil::Histograms histograms_FJ0_SF;
    histograms_FJ0_SF.addHistogram("SFVMD0" , 10000  , 0     , 1     , [&]() { return VMD0(); } );
    RooUtil::Histograms histograms_3FJ_SR;
    histograms_3FJ_SR.addHistogram("SR1SumPtFJ", {1250, 1500, 1750, 2000, 2500, 3000, 4000} , [&]() { return SumPtFJ(); } );
    histograms_3FJ_SR.addHistogram("SR2SumPtFJ", {1250, 1500, 1750, 2000, 3000} , [&]() { if (SumPtFJ() < 2500) return SumPtFJ(); else return 2500.f; } );

    // Book cutflows
    // ana.cutflow.bookCutflows(); // This slow things down so try to keep it commented out and use only when necessary

    // Book Histograms
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_FJ0, "OL");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_FJ0_SF, "OL");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_event, "OL");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_onelep, "OL");

    ana.cutflow.bookHistogramsForCutAndBelow(histograms_FJ0, "ZL2FJ");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_FJ1, "ZL2FJ");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_event, "ZL2FJ");

    ana.cutflow.bookHistogramsForCutAndBelow(histograms_FJ0, "ZL3FJ");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_FJ1, "ZL3FJ");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_FJ2, "ZL3FJ");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_event, "ZL3FJ");
    ana.cutflow.bookHistogramsForCutAndBelow(histograms_3FJ_SR, "ZL3FJ");

    // Looping input file
    while (ana.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (result.count("job_index") and result.count("nsplit_jobs"))
        {
            if (ana.looper.getNEventsProcessed() % ana.nsplit_jobs != (unsigned int) ana.job_index)
                continue;
        }

        //Do what you need to do in for each event here
        //To save use the following function
        ana.cutflow.fill();
    }

    // Writing output file
    ana.cutflow.saveOutput();

    // The below can be sometimes crucial
    delete ana.output_tfile;
}

#!/bin/env python3

import plottery_wrapper as p
import plot_config as c
from systematics import systs

for sig in ["dim6"]:

    data_fname = f"{c.mdir}/jetht.root"

    signal_scale = 137.64/59.83
    # signal_scale = "auto"
    # signal_scale = 1

    histxaxislabeloptions = {
            "SR3SumPtFJ"  : {"xaxis_label" : "H_{T,Fat-Jet} [GeV]"    , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "SR2SumPtFJ"  : {"xaxis_label" : "H_{T,Fat-Jet} [GeV]"    , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "SR1SumPtFJ"  : {"xaxis_label" : "H_{T,Fat-Jet} [GeV]"    , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "SumPtFJFit"  : {"xaxis_label" : "H_{T,Fat-Jet} [GeV]"    , "xaxis_ndivisions" : 505, "nbins": 60, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "HT_binned"   : {"xaxis_label" : "H_{T} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "HTJ_binned"  : {"xaxis_label" : "H_{T} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "HT"          : {"xaxis_label" : "H_{T} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "SR1HTFJ"     : {"xaxis_label" : "H_{T,Fat-Jet,MET} [GeV]", "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "SR2HTFJ"     : {"xaxis_label" : "H_{T,Fat-Jet,MET} [GeV]", "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "HTFJ"        : {"xaxis_label" : "H_{T,Fat-Jet,MET} [GeV]", "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True , "divide_by_bin_width": False},
            "SumPtFJ"     : {"xaxis_label" : "H_{T,Fat-Jet} [GeV]"    , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "SumPtJ"      : {"xaxis_label" : "H_{T,AK4Jet} [GeV]"     , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "VMD0"        : {"xaxis_label" : "V_{MD,lead}"            , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "VMD1"        : {"xaxis_label" : "V_{MD,sublead}"         , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "VMD2"        : {"xaxis_label" : "V_{MD,trail}"           , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "WMD0"        : {"xaxis_label" : "W_{MD,lead}"            , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "WMD1"        : {"xaxis_label" : "W_{MD,sublead}"         , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "Pt01"        : {"xaxis_label" : "p_{T,01} [GeV]"         , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "Pt0"         : {"xaxis_label" : "p_{T,lead} [GeV]"       , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "Pt1"         : {"xaxis_label" : "p_{T,sublead} [GeV]"    , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "Pt2"         : {"xaxis_label" : "p_{T,trail} [GeV]"      , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "Mass0"       : {"xaxis_label" : "M_{lead} [GeV]"         , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "Mass1"       : {"xaxis_label" : "M_{sublead} [GeV]"      , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "Mass2"       : {"xaxis_label" : "M_{trail} [GeV]"        , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "Mass01"      : {"xaxis_label" : "M_{01} [GeV]"           , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "Mass02"      : {"xaxis_label" : "M_{02} [GeV]"           , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "Mass12"      : {"xaxis_label" : "M_{12} [GeV]"           , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "DPhi01"      : {"xaxis_label" : "#Delta#phi_{01}"        , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "DPhi02"      : {"xaxis_label" : "#Delta#phi_{02}"        , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "DPhi12"      : {"xaxis_label" : "#Delta#phi_{12}"        , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": False},
            "NbLoose"     : {"xaxis_label" : "NbLoose"                , "xaxis_ndivisions" : 505, "nbins": 7 , "signal_scale": signal_scale, "yaxis_log": False},
            "NbMedium"    : {"xaxis_label" : "NbMedium"               , "xaxis_ndivisions" : 505, "nbins": 7 , "signal_scale": signal_scale, "yaxis_log": False},
            "NbTight"     : {"xaxis_label" : "NbTight"                , "xaxis_ndivisions" : 505, "nbins": 7 , "signal_scale": signal_scale, "yaxis_log": False},
            "NoORNbLoose" : {"xaxis_label" : "NoORNbLoose"            , "xaxis_ndivisions" : 505, "nbins": 7 , "signal_scale": signal_scale, "yaxis_log": False},
            "NoORNbMedium": {"xaxis_label" : "NoORNbMedium"           , "xaxis_ndivisions" : 505, "nbins": 7 , "signal_scale": signal_scale, "yaxis_log": False},
            "NoORNbTight" : {"xaxis_label" : "NoORNbTight"            , "xaxis_ndivisions" : 505, "nbins": 7 , "signal_scale": signal_scale, "yaxis_log": False},
            "MVVX"        : {"xaxis_label" : "M_{VVX} [GeV]"          , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "MET"         : {"xaxis_label" : "MET [GeV]"              , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "SRMET"       : {"xaxis_label" : "MET [GeV]"              , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "yaxis_log": True },
            "Yield"       : {"xaxis_label" : "Yield"                  , "xaxis_ndivisions" : 505, "nbins": 1 , "signal_scale": signal_scale, "yaxis_log": False},
            }

    cut_subregions = ["Presel", "A", "B", "C", "D", "E", "F"]
    cut_channels = ["ZL3FJ", "ZL2FJ", "ZL2FJLMET", "ZL2FJHMET"]

    # Creating cut region names
    cut_regions = []
    for ch in cut_channels:
        for sr in cut_subregions:
            cut_regions.append(f"{ch}{sr}")
    cut_regions.append("ZL3FJTop")

    # Create filter patterns putting together cut regions and histogram names
    filter_patterns = []
    for cut_region in cut_regions:
        for hist_name in histxaxislabeloptions.keys():
            filter_patterns.append(f"{cut_region}__{hist_name}")
    filter_pattern = ",".join(filter_patterns)

    ## MC Out-of-the-box
    c.extraoptions["yaxis_log"] = False

    ## MC out-of-the-box
    p.dump_plot(
            fnames = c.fnames,
            legend_labels = c.legend_labels,
            sig_fnames = c.sig_fnames_dim8 if sig == "dim8" else c.sig_fnames_dim6,
            signal_labels = c.signal_labels_dim8 if sig == "dim8" else c.signal_labels_dim6,
            data_fname = data_fname,
            usercolors = c.usercolors,
            filter_pattern = filter_pattern,
            dirname = f"plots/ZL/{c.tag}/{sig}/mc",
            dogrep = False,
            extraoptions = c.extraoptions,
            histxaxislabeloptions = histxaxislabeloptions,
            )

    ## Data-Driven histograms (there are only a few)
    histograms = [
            "ZL3FJA__SR1SumPtFJ",
            "ZL3FJA__SumPtFJFit",
            "ZL3FJE__SR1SumPtFJ",
            "ZL3FJE__SumPtFJFit",
            "ZL2FJA__HTJ_binned",
            "ZL2FJE__HTJ_binned",
            "ZL2FJLMETA__SR2HTFJ",
            "ZL2FJLMETE__SR2HTFJ",
            ]
    filter_patterns = []
    for hist in histograms:
            filter_patterns.append(f"{hist}")
    filter_pattern = ",".join(filter_patterns)

    ## Data Driven
    p.dump_plot(
            fnames = c.ddfnames,
            legend_labels = c.ddlegend_labels,
            sig_fnames = c.sig_fnames_dim8 if sig == "dim8" else c.sig_fnames_dim6,
            signal_labels = c.signal_labels_dim8 if sig == "dim8" else c.signal_labels_dim6,
            data_fname = data_fname,
            usercolors = c.ddusercolors,
            filter_pattern = filter_pattern,
            dirname = f"plots/ZL/{c.tag}/{sig}/abcd",
            dogrep = False,
            extraoptions = c.extraoptions,
            histxaxislabeloptions = histxaxislabeloptions,
            )

    ## Data-Driven Fitted histograms
    histograms = [
            "ZL3FJA__SR1SumPtFJ",
            "ZL3FJE__SR1SumPtFJ",
            ]
    filter_patterns = []
    for hist in histograms:
            filter_patterns.append(f"{hist}")
    filter_pattern = ",".join(filter_patterns)

    ## Data Driven
    p.dump_plot(
            fnames = c.ddfnames_fit,
            legend_labels = c.ddlegend_labels,
            sig_fnames = c.sig_fnames_dim8 if sig == "dim8" else c.sig_fnames_dim6,
            signal_labels = c.signal_labels_dim8 if sig == "dim8" else c.signal_labels_dim6,
            data_fname = data_fname,
            usercolors = c.ddusercolors,
            filter_pattern = filter_pattern,
            dirname = f"plots/ZL/{c.tag}/{sig}/fit",
            dogrep = False,
            extraoptions = c.extraoptions,
            histxaxislabeloptions = histxaxislabeloptions,
            )


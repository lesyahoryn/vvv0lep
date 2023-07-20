#!/bin/env python3

import plottery_wrapper as p
import plot_config as c

for sig in ["dim6"]:

    data_fname = f"{c.mdir}/jetht.root"

    signal_scale = 137.64/59.83

    c.extraoptions["signal_scale"] = signal_scale
    c.extraoptions["yield_prec"] = 10

    filter_patterns = []

    cut_regions = ["ZL3FJ", "ZL2FJ"]
    for cut_region in cut_regions:
        filter_patterns.append(f"{cut_region}__Cutflow3FJ")
        filter_patterns.append(f"{cut_region}__Cutflow2FJ")
        filter_patterns.append(f"{cut_region}__Cutflow2FJLMET")
        filter_patterns.append(f"{cut_region}__Cutflow2FJHMET")

    cut_regions = [
            "ZL3FJA",
            "ZL3FJB",
            "ZL3FJC",
            "ZL3FJD",
            "ZL3FJE",
            "ZL3FJF",
            ]
    for cut_region in cut_regions:
        filter_patterns.append(f"{cut_region}__Yield")
        filter_patterns.append(f"{cut_region}__SR1SumPtFJ")
    cut_regions = [
            "ZL2FJA",
            "ZL2FJB",
            "ZL2FJC",
            "ZL2FJD",
            "ZL2FJE",
            "ZL2FJF",
            ]
    for cut_region in cut_regions:
        filter_patterns.append(f"{cut_region}__Yield")
        filter_patterns.append(f"{cut_region}__HTJ_binned")
    cut_regions = [
            "ZL2FJLMETA",
            "ZL2FJLMETB",
            "ZL2FJLMETC",
            "ZL2FJLMETD",
            "ZL2FJLMETE",
            "ZL2FJLMETF",
            ]
    for cut_region in cut_regions:
        filter_patterns.append(f"{cut_region}__Yield")
        filter_patterns.append(f"{cut_region}__SR2HTFJ")
    cut_regions = [
            "ZL2FJHMETA",
            "ZL2FJHMETB",
            "ZL2FJHMETC",
            "ZL2FJHMETD",
            "ZL2FJHMETE",
            "ZL2FJHMETF",
            ]
    for cut_region in cut_regions:
        filter_patterns.append(f"{cut_region}__Yield")
        filter_patterns.append(f"{cut_region}__SR1HTFJ")

    filter_pattern = ",".join(filter_patterns)

    ## MC Out-of-the-box
    c.extraoptions["yaxis_log"] = False
    p.dump_plot(
            fnames = c.fnames,
            legend_labels = c.legend_labels,
            sig_fnames = c.sig_fnames_dim8 if sig == "dim8" else c.sig_fnames_dim6,
            signal_labels = c.signal_labels_dim8 if sig == "dim8" else c.signal_labels_dim6,
            data_fname = data_fname,
            usercolors = c.usercolors,
            filter_pattern = filter_pattern,
            dirname = f"plots/Cutflows/{c.tag}/{sig}/mc",
            dogrep = False,
            extraoptions = c.extraoptions,
            )

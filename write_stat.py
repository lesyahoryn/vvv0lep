#!/bin/env python3

import ROOT as r
import plot_config as c
import sys
from systematics import systs
import json
import os

systs = ["Nominal"]

def suffix(syst):
    if "JESUp" in syst: return "_jes_Up"
    elif "JESDn" in syst: return "_jes_Down"
    elif "JERUp" in syst: return "_jer_Up"
    elif "JERDn" in syst: return "_jer_Down"
    elif "JMSUp" in syst: return "_jms_Up"
    elif "JMSDn" in syst: return "_jms_Down"
    elif "JMRUp" in syst: return "_jmr_Up"
    elif "JMRDn" in syst: return "_jmr_Down"
    elif "prefireWgtUp" in syst: return "_prefire_weight_Up"
    elif "prefireWgtDn" in syst: return "_prefire_weight_Down"
    elif "puWgtUp" in syst: return "_pu_weight_Up"
    elif "puWgtDn" in syst: return "_pu_weight_Down"
    elif "trigWgtUp" in syst: return "_trigger_weight_Up"
    elif "trigWgtDn" in syst: return "_trigger_weight_Down"
    else: return ""

def zero_out_negative(h):
    for i in range(0, h.GetNbinsX()+2):
        if h.GetBinContent(i) < 0:
            h.SetBinContent(i, 0)

def write_cards(version, channel, hn):

    os.system("mkdir -p datacards")

    hist_name = f"ZL{channel}A__{hn}"
    stat_file_name = f"datacards/VVV.0L_{channel}.DataCard_Yields.{version}.root"
    stat_file = r.TFile(stat_file_name, "RECREATE")

    samples = ["WW", "WZ", "ZZ", "ttV", "QCD", "WJets", "DY", "TTbar"]

    for s in samples:
        for syst in systs:
            dirname = f"{c.mdir}"
            bg_files = c.ddfnames
            syst_suffix = suffix(syst)
            f = r.TFile(f"{dirname}/{s}.root")
            h = f.Get(hist_name).Clone()
            h.SetName(f"h_{s}{syst_suffix}")
            print("before")
            h.Print("all")
            zero_out_negative(h)
            print("before")
            h.Print("all")
            h.SetDirectory(stat_file)
            stat_file.cd()
            h.Write()

    f_eft_idx_information = open("data/dim6_eft_information.txt")
    j = json.loads(f_eft_idx_information.read())

    signals = ["vvvdim6"]
    signames = {"vvvdim6": "WWW"}

    for eft_idx in range(91):
        for s in signals:
            for syst in systs:
                syst_suffix = suffix(syst)
                dirname = f'{c.mdir}'
                f = r.TFile(f"{dirname}/{s}.root")
                idx = eft_idx
                eft_name = j[str(eft_idx)]
                hist_name = f"ZL{channel}AEFTIDX{idx}__{hn}"
                h = f.Get(hist_name).Clone()
                h.SetName(f"h_{signames[s]}_{eft_name}{syst_suffix}")
                h.SetDirectory(stat_file)
                h.Scale(137.64/59.83)
                stat_file.cd()
                h.Write()


    stat_file.Close()

if __name__ == "__main__":

    version = "v11"
    write_cards(version, "2FJ", "HTJ_binned")
    # write_cards(version, "2FJLMET", "HTJ_binned")
    # write_cards(version, "2FJHMET", "HTJ_binned")
    write_cards(version, "3FJ", "SR1SumPtFJ")

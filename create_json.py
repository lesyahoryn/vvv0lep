#!/bin/env python3

import glob
import ROOT as r
import os
import json
import socket

if "uaf-2" in socket.gethostname():
    tag = "VVV0TreeV10_3FJ"
    sample_dirs = glob.glob(f"/data/userdata/phchang/VVV0LepAnalysis/{tag}/*_{tag}")
else:
    tag = "VVV0TreeV8"
    sample_dirs = glob.glob(f"/ceph/cms/store/user/phchang/VVV0LepAnalysis/{tag}/*_{tag}")
os.system(f"mkdir -p data/samples/{tag}")

xsec_json_file = open("data/MCxsec.json")
xsec_json = json.loads(xsec_json_file.read())

def parse_sample_category(name, json):

    # Check it's data
    if "Run201" in name:
        json["is_sig"] = 0
        json["is_bkg"] = 0
        json["is_data"] = 1
        return

    # Check it's signal
    signal_patterns = [
            "WWW_NoFilter",
            "WWZ_NoFilter",
            "WZZ_NoFilter",
            "ZZZ_NoFilter",
            "WWW_4F",
            "WWZ_4F",
            "WZZ_Tune",
            "ZZZ_Tune",
            ]
    for sp in signal_patterns:
        if sp in name:
            json["is_sig"] = 1
            json["is_bkg"] = 0
            json["is_data"] = 0
            return

    # at this point it's always background
    json["is_sig"] = 0
    json["is_bkg"] = 1
    json["is_data"] = 0
    return

def parse_eft_sample(name, json):
    if "NoFilter" in name:
        json["is_eft"] = 1
    else:
        json["is_eft"] = 0

def get_sample_name(name, json):
    n = os.path.basename(name)
    json["name"] = n.split("_VVV0Tree")[0]
    if json["is_bkg"] or json["is_sig"]:
        json["process"] = json["name"].split("_RunII")[0]
    else:
        json["process"] = json["name"].split("_Run201")[0] + "_Run201" + json["name"].split("_Run201")[1][0:2]

def get_sample_dir(name, json):
    json["dir"] = name

def get_xsec(d, json):
    if json["is_bkg"] or json["is_sig"]:
        json["xsec"] = xsec_json[json["process"]]
    else:
        json["xsec"] = 1

def get_lumi_and_year(d, json):
    if json["is_bkg"] or json["is_sig"]:
        if "UL16NanoAODAPVv9" in json["name"]:
            json["lumi"] = 19.52
            json["year"] = 2006
        elif "UL16NanoAODv9" in json["name"]:
            json["lumi"] = 16.81
            json["year"] = 2016
        elif "UL17NanoAODv9" in json["name"]:
            json["lumi"] = 41.48
            json["year"] = 2017
        elif "UL18NanoAODv9" in json["name"]:
            json["lumi"] = 59.83
            json["year"] = 2018
        else:
            json["lumi"] = 137.64
            json["year"] = -1
    else:
        json["lumi"] = 1
        if "Run2016" in json["name"] and "HIPM" in json["name"]:
            json["year"] = 2006
        elif "Run2016" in json["name"]:
            json["year"] = 2016
        elif "Run2017" in json["name"]:
            json["year"] = 2017
        elif "Run2018" in json["name"]:
            json["year"] = 2018
        else:
            json["year"] = -1

def build_output_dir(d, json):
    json["output_dir"] = f'output/{json["tag"]}/{json["year"]}/{json["process"]}'

def parse_sample(d, j):
    parse_sample_category(d, j)
    parse_eft_sample(d, j)
    get_sample_dir(d, j)
    get_sample_name(d, j)
    get_xsec(d, j)
    get_lumi_and_year(d, j)
    build_output_dir(d, j)

def main():

    for d in sample_dirs:
        print(f"Processing sample: {d}")
        j = dict()
        rootfiles = glob.glob(f"{d}/*.root")
        j["tag"] = tag
        j["noriginalevents"] = int(0)
        j["sum_genWeight"] = 0
        j["nfiles"] = len(rootfiles)
        j["files"] = rootfiles
        j["nevents"] = []
        parse_sample(d, j)
        # if not j["process"] == "WWZ_NoFilter_NoGGPartons_Dim6":
        #     continue
        for rf in rootfiles:
            print(f"  Processing file: {rf}")
            f = r.TFile(rf)
            j["nevents"].append(f.Get("t").GetEntries())
            j["noriginalevents"] += int(f.Get("Root__h_nevents").GetBinContent(1))
            if j["is_eft"]:
                j["sum_genWeight"] += f.Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight").GetBinContent(1)
            elif j["is_bkg"] or j["is_sig"]:
                j["sum_genWeight"] += f.Get("Root__h_Common_genWeight").GetBinContent(1)
        json_formatted_str = json.dumps(j, indent=4)
        jfile = open(f'data/samples/{tag}/{j["name"]}.json', "w")
        jfile.write(json_formatted_str)

if __name__ == "__main__":

    main()

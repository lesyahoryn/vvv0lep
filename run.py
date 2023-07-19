#!/bin/env python3

import os
import glob
import json
from systematics import systs
import plot_config as c


eft_dim8 = {
    "WWW": { "43": "EFT__FM0_p2", "91":  "EFT__FT0_p2", "7": "EFT__FS0_p2"},
    "WWZ": { "42": "EFT__FM0_p2", "138": "EFT__FT0_p2", "6": "EFT__FS0_p2"},
    "WZZ": { "42": "EFT__FM0_p2", "138": "EFT__FT0_p2", "6": "EFT__FS0_p2"},
    "ZZZ": { "42": "EFT__FM0_p2", "138": "EFT__FT0_p2", "6": "EFT__FS0_p2"}
}

eft_dim6 = {
    "WWW": { "12": "EFT__cW_0p1" },
    "WWZ": { "12": "EFT__cW_0p1" },
    "WZZ": { "12": "EFT__cW_0p1" },
    "ZZZ": { "12": "EFT__cW_0p1" }
}

eft_to_run = eft_dim6


nchunk = 1.5e6
jobconfigs = glob.glob(f"data/samples/{c.tag}/*.json")
os.system("rm -f .jobs.txt")
jobs = open(".jobs.txt", "w")

def chunks(j, nchunk):
    tmp = 0
    cs = []
    c = []
    for n, f in zip(j["nevents"], j["files"]):
        tmp += n
        c.append(f)
        if tmp > nchunk:
            cs.append(c)
            c = []
            tmp = 0
    if len(c) != 0:
        cs.append(c)
    return cs

for jobconfig in jobconfigs:
    f = open(jobconfig)
    j = json.loads(f.read())

    cs = chunks(j, nchunk)

    tag = j["tag"]
    process = j["process"]
    output_dir = j["output_dir"]

    for job_index in range(len(cs)):
        for syst in systs:
            output_name = f"output_{job_index}.root"
            output_fullpath = f"{output_dir}/{syst}/{output_name}"
            os.system(f"mkdir -p {output_dir}/{syst}")
            output_log_fullpath = output_fullpath.replace(".root", ".log")
            inputs = ",".join(cs[job_index])
            if out_name.strip(".root") not in eft_to_run:
                print out_name
                jobs.write(f"./doAnalysis --json {jobconfig} -i {inputs} -o {output_fullpath} -t t -s {syst} > {output_log_fullpath} 2>&1\n")
            else:
                for idx in eft_to_run[out_name.strip(".root")]:
                    out_name = f.split("/")[-1]
                    out_name = out_name.strip(".root") + "_" + eft_to_run[out_name.strip(".root")][idx] + ".root"
                    print out_name
                    subprocess.call(["./doVVVAnalysis", "--input", args.inPath+f, "--tree", "t", "--mode", "8", "-V", "--output", out_name, "-e", idx] )
                    subprocess.call(["mv", out_name, args.outPath])



jobs.close()

os.system("xargs.sh .jobs.txt")

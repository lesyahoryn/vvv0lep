#!/bin/env python3

import os
import glob
import json
import plot_config as c
import sys
import socket

run_test = False
if len(sys.argv) > 1:
    run_test = True


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

    if run_test:
        if "Dim" not in process:
            continue

    for job_index in range(len(cs)):
        output_name = f"output_{job_index}.root"
        output_fullpath = f"{output_dir}/{output_name}"
        os.system(f"mkdir -p {output_dir}/")
        output_log_fullpath = output_fullpath.replace(".root", ".log")
        inputs = ",".join(cs[job_index])
        jobs.write(f"./doAnalysis --json {jobconfig} -i {inputs} -o {output_fullpath} -t t > {output_log_fullpath} 2>&1\n")

jobs.close()

if "uaf-2" in socket.gethostname():
    os.system("xargs.sh .jobs.txt")
else:
    os.system("xargs.sh .jobs.txt")

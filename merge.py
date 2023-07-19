#!/bin/env python3

import sys
import glob
import ROOT as r
import os
import json
import plot_config as c

merge_json_file = open("data/merge.json")
merge_json = json.loads(merge_json_file.read())

merge_jobs = ".merge.txt"
os.system(f"rm -f {merge_jobs}")
merge_jobs_command_file = open(f"{merge_jobs}", "w")

to_be_merged = {}
for key in merge_json.keys():
    for categs in merge_json[key]:
        to_be_merged[categs] = {}
        to_be_merged[categs][2006] = []
        to_be_merged[categs][2016] = []
        to_be_merged[categs][2017] = []
        to_be_merged[categs][2018] = []
        to_be_merged[categs]["Run2"] = []

sample_jsons = glob.glob(f"data/samples/{c.tag}/*")
for sample_json in sample_jsons:
    f = open(sample_json)
    sj = json.loads(f.read())
    output_dir = sj["output_dir"]
    output_files = glob.glob(f'{output_dir}/*.root')
    merge_categories = merge_json[sj["process"]]
    year = sj["year"]
    for categ in merge_categories:
        to_be_merged[categ][year] += output_files
        to_be_merged[categ]["Run2"] += output_files

for key in to_be_merged:
    for year in [2006, 2016, 2017, 2018, "Run2"]:
        merge_output_dir = f"output/{c.tag}/{year}/merged/"
        os.system(f"mkdir -p {merge_output_dir}")

for key in to_be_merged:
    for year in [2006, 2016, 2017, 2018, "Run2"]:
        merge_output_dir = f"output/{c.tag}/{year}/merged/"
        if len(to_be_merged[key][year]) == 0:
            continue
        files = " ".join(to_be_merged[key][year])
        merge_output_file = f"{merge_output_dir}/{key}.root"
        merge_output_log = f"{merge_output_dir}/{key}.log"
        merge_jobs_command_file.write(f"hadd -f {merge_output_file} {files} > {merge_output_log} 2>&1\n")

merge_jobs_command_file.close()

os.system("xargs.sh .merge.txt")

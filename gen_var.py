#!/bin/env python3

var_wo_syst = ["isData",
"run",
# "lumi",
"evt",
# "year",
"genWeight",
"wgt",
"LHEReweightingWeight",
"trigger",
"is0Lep",
"is1Lep",
"Lep",
"LepFlav",
"GenV0",
"GenV1",
"GenV2",
"isHad0",
"isHad1",
"isHad2",
"GenF00",
"GenF01",
"GenF10",
"GenF11",
"GenF20",
"GenF21",
]

var_w_syst = ["NFJ",
"FJ0",
"FJ1",
"FJ2",
"FJ3",
"FJ4",
"VMD0",
"VMD1",
"VMD2",
"VMD3",
"VMD4",
"WMD0",
"WMD1",
"WMD2",
"WMD3",
"WMD4",
"NQGen0",
"NQGen1",
"NQGen2",
"NQGen3",
"NQGen4",
"NBGen0",
"NBGen1",
"NBGen2",
"NBGen3",
"NBGen4",
"NLGen0",
"NLGen1",
"NLGen2",
"NLGen3",
"NLGen4",
"NiFJ",
"iFJ0",
"iFJ1",
"iFJ2",
"iFJ3",
"iFJ4",
"iVMD0",
"iVMD1",
"iVMD2",
"iVMD3",
"iVMD4",
"iWMD0",
"iWMD1",
"iWMD2",
"iWMD3",
"iWMD4",
"MET",
"Nu",
"NJ",
"NbLoose",
"NbMedium",
"NbTight",
"NoORNbLoose",
"NoORNbMedium",
"NoORNbTight",
"J0",
"J1",
"J2",
"J3",
"J4",
"MVVX",
"PtVVX",
"HT",
"HTJ",
"HTFJ",
"SumPtFJ",
"SumPtJ",
]

wgt_syst = ["prefireWgt",
# "prefireWgtUp",
# "prefireWgtDn",
"puWgt",
# "puWgtUp",
# "puWgtDn",
"trigWgt",
# "trigWgtUp",
# "trigWgtDn",
]

syst_template = lambda VAR: f"""auto {VAR} = [&](TString syst_name="Nominal")
{{
    if (syst_name.EqualTo("Nominal"))
        return vvv.{VAR}();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.{VAR}JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.{VAR}JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.{VAR}JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.{VAR}JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.{VAR}JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.{VAR}JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.{VAR}JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.{VAR}JMRDn();
    else
        return vvv.{VAR}();
}};

"""

wo_syst_template = lambda VAR: f"""auto {VAR} = [&]()
{{
    return vvv.{VAR}();
}};

"""

wgt_syst_template = lambda VAR: f"""auto {VAR} = [&]()
{{
    if (ana.syst_name.EqualTo("{VAR}Up"))
        return vvv.{VAR}Up();
    else if (ana.syst_name.EqualTo("{VAR}Dn"))
        return vvv.{VAR}Dn();
    else
        return vvv.{VAR}();
}};

"""

var_w_syst_strs = []
for v in var_w_syst:
    var_w_syst_strs.append(syst_template(v))

var_wo_syst_strs = []
for v in var_wo_syst:
    var_wo_syst_strs.append(wo_syst_template(v))

wgt_syst_strs = []
for v in wgt_syst:
    wgt_syst_strs.append(wgt_syst_template(v))

f = open("variable.h", "w")

for i in var_w_syst_strs:
    f.write(i)

for i in var_wo_syst_strs:
    f.write(i)

for i in wgt_syst_strs:
    f.write(i)

f.close()

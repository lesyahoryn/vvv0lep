#!/bin/bash

echo "----------------------------"
echo "ZL3FJ Cutflow"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL3FJ__Cutflow3FJ.txt

echo "----------------------------"
echo "ZL2FJ Cutflow"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL2FJ__Cutflow2FJ.txt

echo "----------------------------"
echo "ZL2FJ Low MET Cutflow"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL2FJ__Cutflow2FJLMET.txt

echo "----------------------------"
echo "ZL2FJ High MET Cutflow"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL2FJ__Cutflow2FJHMET.txt

echo "----------------------------"
echo "ZL3FJ ABCDEF"
echo "----------------------------"
#-----------
HEADER=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL3FJA__Yield.txt | head -n 1)
echo ${HEADER}
CUTS="ZL3FJA ZL3FJB ZL3FJC ZL3FJD ZL3FJE ZL3FJF"
for CUT in ${CUTS}; do
    LINE=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/${CUT}__Yield.txt | tail -n 2 | head -n 1)
    echo ${LINE/Bin1/${CUT}}
done

echo "----------------------------"
echo "ZL2FJ ABCDEF"
echo "----------------------------"
#-----------
HEADER=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL2FJA__Yield.txt | head -n 1)
echo ${HEADER}
CUTS="ZL2FJA ZL2FJB ZL2FJC ZL2FJD ZL2FJE ZL2FJF"
for CUT in ${CUTS}; do
    LINE=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/${CUT}__Yield.txt | tail -n 2 | head -n 1)
    echo ${LINE/Bin1/${CUT}}
done

echo "----------------------------"
echo "ZL2FJ LowMET ABCDEF"
echo "----------------------------"
#-----------
HEADER=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL2FJLMETA__Yield.txt | head -n 1)
echo ${HEADER}
CUTS="ZL2FJLMETA ZL2FJLMETB ZL2FJLMETC ZL2FJLMETD ZL2FJLMETE ZL2FJLMETF"
for CUT in ${CUTS}; do
    LINE=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/${CUT}__Yield.txt | tail -n 2 | head -n 1)
    echo ${LINE/Bin1/${CUT}}
done

echo "----------------------------"
echo "ZL3FJA SR1SumPtFJ (MC Only Yields)"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/ZL/VVV0TreeV7/dim6/mc/ZL3FJA__SR1SumPtFJ.txt

echo "----------------------------"
echo "ZL2FJA HTJ_binned (MC Only Yields)"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/ZL/VVV0TreeV7/dim6/mc/ZL2FJA__HTJ_binned.txt

echo "----------------------------"
echo "ZL2FJA Low MET SR2HTFJ (MC Only Yields)"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/ZL/VVV0TreeV7/dim6/mc/ZL2FJLMETA__SR2HTFJ.txt

echo "----------------------------"
echo "ZL2FJA High MET SR1HTFJ (MC Only Yields)"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/ZL/VVV0TreeV7/dim6/mc/ZL2FJHMETA__SR1HTFJ.txt

echo "----------------------------"
echo "ZL3FJA ABCD SR1SumPtFJ (Data Driven)"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/ZL/VVV0TreeV7/dim6/abcd/ZL3FJA__SR1SumPtFJ.txt

echo "----------------------------"
echo "ZL2FJA ABCD HTJ_binned (Data Driven)"
echo "----------------------------"
python rooutil/python/yield_for_keynote.py  plots/ZL/VVV0TreeV7/dim6/abcd/ZL2FJA__HTJ_binned.txt

echo "----------------------------"
echo "ZL3FJ ABCDEF SR1SumPtFJ"
echo "----------------------------"
HEADER=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL3FJA__Yield.txt | head -n 1)
echo ${HEADER}
CUTS="ZL3FJA ZL3FJB ZL3FJC ZL3FJD ZL3FJE ZL3FJF"
NLINERAW=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL3FJA__SR1SumPtFJ.txt | wc -l)
NLINE=$((NLINERAW-4))
NLINEONE=$((NLINE+1))
for CUT in ${CUTS}; do
    echo ${CUT}
    LINE=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/${CUT}__SR1SumPtFJ.txt | tail -n ${NLINEONE} | head -n ${NLINE})
    echo ${LINE} | tr ' ' '\n'
done

echo "----------------------------"
echo "ZL2FJ ABCDEF HTJ_binned"
echo "----------------------------"
HEADER=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL2FJA__Yield.txt | head -n 1)
echo ${HEADER}
CUTS="ZL2FJA ZL2FJB ZL2FJC ZL2FJD ZL2FJE ZL2FJF"
NLINERAW=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/ZL2FJA__HTJ_binned.txt | wc -l)
NLINE=$((NLINERAW-4))
NLINEONE=$((NLINE+1))
for CUT in ${CUTS}; do
    echo ${CUT}
    LINE=$(python rooutil/python/yield_for_keynote.py  plots/Cutflows/VVV0TreeV7/dim6/mc/${CUT}__HTJ_binned.txt | tail -n ${NLINEONE} | head -n ${NLINE})
    echo ${LINE} | tr ' ' '\n'
done


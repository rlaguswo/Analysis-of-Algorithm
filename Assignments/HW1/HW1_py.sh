#!/bin/bash
echo "Insertion Sort"

python3 insertsort.py > insert.txt
python3 insertsort.py
echo

echo "Merge Sort"

python3 mergesort.py > merge.txt
python3 mergesort.py
echo
echo "Correctly sotred data"
cat sorted.txt
echo

diff -y -B -b --report-identical-files --suppress-common-lines insert.txt sorted.txt
echo
diff -y -B -b --report-identical-files --suppress-common-lines merge.txt sorted.txt
echo
echo "Insertion Sort times"
python3 insertTime.py
echo
echo "Merge Sort times"
python3 mergeTime.py


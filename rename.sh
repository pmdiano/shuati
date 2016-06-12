#!/bin/bash
# This script renames 1-digit and 2-digit folders to 3-digit
# so that all the LeetCode auto-checkins are sorted according
# to their #.
# 
# Qirong Ma
# 06/11/2016
# 

changes=0

for directory in $(ls -d */); do
    directory=${directory%%/}
    if [[ ${directory:1:1} == "-" ]]; then
        # 1 digit, add two 0
        d2="00$directory"
    elif [[ ${directory:2:1} == "-" ]]; then
        # 2 digit, add one 0
        d2="0$directory"
    else
        # 3 digit, do nothing
        d2="$directory"
    fi

    if [[ ${directory} != ${d2} ]]; then
        echo changing ${directory} to ${d2}
        git mv ${directory} ${d2}
        ((changes++))
    fi
done

echo Commiting $changes changes..
git add ./
git commit -m "Rename numbers"
git push

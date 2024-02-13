#!/bin/bash

total_part1=0
total_part2=0
total_all=0

while IFS= read -r line
do
    if [[ $line =~ ([0-9]{2}):([0-9]{2}):([0-9]{2}) ]]
    then
        # Extract part1 and part2 times
        part1_time=$(echo $line | cut -d'|' -f3)
        part2_time=$(echo $line | cut -d'|' -f4)

        # Remove leading and trailing whitespaces
        part1_time=$(echo $part1_time | xargs)
        part2_time=$(echo $part2_time | xargs)

        # Convert times to seconds
        part1_seconds=$(date -d"$part1_time" +%s)
        part2_seconds=$(date -d"$part2_time" +%s)

        # Add to total times
        total_part1=$((total_part1 + part1_seconds))
        total_part2=$((total_part2 + part2_seconds))
    fi
done < README.md

total_all=$((total_part1 + total_part2))

total_part1=$(date -u -d @${total_part1} +"%T")
total_part2=$(date -u -d @${total_part2} +"%T")
total_all=$(date -u -d @${total_all} +"%T")

echo "Total time for Part 1: $total_part1"
echo "Total time for Part 2: $total_part2"
echo "Total time for all parts: $total_all"
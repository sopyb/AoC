#!/bin/bash

total_seconds=0
total_milliseconds=0

times=$(grep -oP 'Day \d+ \(\K[^)]*' README.md)

for time in $times; do
    if [[ $time == *h* ]]; then
        hours=${time//\~/}
        hours=${hours//h}
        ((total_seconds += 10#$hours * 3600))
    elif [[ $time == *:*.* ]]; then
        IFS=":" read minutes rest <<< "$time"
        IFS="." read seconds milliseconds <<< "$rest"
        milliseconds=$(printf "%02d0" $milliseconds)
        ((total_seconds += 10#$minutes * 60 + 10#$seconds))
        ((total_milliseconds += 10#$milliseconds))
    fi
done

overflow_seconds=$((total_milliseconds / 1000))
total_seconds=$((total_seconds + overflow_seconds))
total_milliseconds=$((total_milliseconds % 1000))

hours=$((total_seconds / 3600))
minutes=$(printf "%02d" $(((total_seconds % 3600) / 60)))
seconds=$(printf "%02d" $((total_seconds % 60)))
total_milliseconds=$(awk -v ms=$total_milliseconds 'BEGIN { printf "%3d", ms }')

echo "Total time: $hours:$minutes:$seconds.$total_milliseconds"
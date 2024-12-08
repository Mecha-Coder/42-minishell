#!/bin/bash

# Iterate through ASCII values from 32 to 127
for i in $(seq 32 127); do
    # Convert ASCII value to character and assign it to X
    X=$(printf "\\$(printf '%03o' "$i")")
    
    # Display input and execute echo command
    echo "input:  \$$X"
    echo "output: $(eval echo \$$X)"
    echo "-------------------------------------"
done
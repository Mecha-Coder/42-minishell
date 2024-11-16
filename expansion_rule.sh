#!/bin/bash

# Loop through ASCII values for printable characters (32 to 126)
for ascii in $(seq 32 126); do
  # Convert ASCII value to the actual character
  char=$(printf "\\$(printf '%03o' "$ascii")")
  
  # Set the variable X to the character
  X="$char"
  
  # Divider line
  echo "----------------------------------------"
  
  # Display the character used
  echo "Evaluating character: \$$X"
  
  # Display the result of evaluating $X in Bash
  echo "Bash output:"
  eval echo "\$$X"
done


#-------------------------
#Rule
#-------------------------
#$[digit] 1 - 9 (Blank)
#$[identifier]
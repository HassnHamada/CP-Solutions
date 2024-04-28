#!/bin/bash

# Read the input file line by line
while read line; do
  # Split the line into fields
  IFS=' ' read -ra fields <<< "$line"
  
  # On the first line, print the header 
  if [ -z "$header" ]; then
    header="${fields[@]}"
    echo "$header"
  # On subsequent lines, print the fields
  else
    echo "${fields[@]}"
  fi
done < file.txt

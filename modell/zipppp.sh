#!/bin/bash

# Define the input file path
input_file="/mnt/Brain/3Code/modell/clojure.core_typing - Matt Adereth [uk3A41U0iO4].webm"

# Define the desired output file size (in bytes)
output_file_size=$((40 * 1024 * 1024)) # 40MB

# Split the input file into smaller files
split --bytes="$output_file_size" "$input_file" "$input_file.part"

# Rename the split files with sequential numbers
counter=1
for file in "$input_file".part*; do
    mv "$file" "$input_file.part$counter"
    counter=$((counter + 1))
done

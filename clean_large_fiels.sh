#!/bin/bash

# Function to recursively search for files larger than 49MB
search_files() {
    local dir="$1"
    local size="49M"
    find "$dir" -type f -size "+$size"
}

# Prompt the user to enter the directory path
read -p "Enter the directory path to search: " directory

# Call the search_files function with the provided directory path
search_files "$directory"

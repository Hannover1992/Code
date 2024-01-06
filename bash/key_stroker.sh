#!/bin/bash

# Function to handle the interruption
cleanup() {
  echo "Script interrupted. Cleaning up..."
  # Include any cleanup commands here (if necessary)
  exit 1
}

# Trap SIGINT (Ctrl+C) and call the cleanup function
trap cleanup SIGINT

# Your commands here (example with xdotool)
xdotool key Super+t
sleep 2
xdotool type 'echo Hello, World!'
xdotool key Return

# Wait or do other tasks
while true; do
  # Your repeating commands or waiting for something
  sleep 1  # Just an example of waiting
  
  # You might want to check for some condition to exit the loop
  # if some_condition; then
  #   break
  # fi
done

# Cleanup and exit (if you have a natural end to your script)
cleanup


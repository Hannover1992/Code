#!/bin/bash

pid_file="pid.txt"
recording_file="myrecording.wav"

# Function to start recording
start_recording() {
    arecord -f cd -t wav $recording_file &
    echo $! > $pid_file
    echo "Recording started with PID $!"
}

# Function to stop recording
stop_recording() {
    if [ -f $pid_file ]; then
        kill $(cat $pid_file)
        rm $pid_file
        echo "Recording stopped."
    else
        echo "No recording is currently running."
    fi
}

# Main logic
if [ -f $pid_file ]; then
    # If recording is in progress, stop it
    stop_recording
else
    # If no recording is in progress, start a new one
    start_recording
fi

#!/bin/bash

# Define the directory and lock file
OUTPUT_DIR="/mnt/Bunkier/uczen/BildSchirmAufnahme"
LOCK_FILE="$OUTPUT_DIR/record.lock"

# Check if the lock file exists
if [ -e "$LOCK_FILE" ]; then
    echo "Another instance is running, or lock file wasn't deleted properly."
    PID=$(cat $LOCK_FILE)
    echo "Currently running instance PID: $PID"
    # Optional: Notify the user that another instance is running
    notify-send "Error" "Another recording instance is already running with PID $PID"
    exit 1
else
    echo $$ > "$LOCK_FILE"
    echo "Lock file created. PID: $$"
fi

# Define the output file name with current date and time
CURRENT_DATE=$(date +'%Y-%m-%d_%H-%M-%S')
OUTPUT_FILE="$OUTPUT_DIR/output_$CURRENT_DATE.mkv"

# Define the FFmpeg command with the new output file name
FFMPEG_CMD="ffmpeg -f x11grab -r 25 -s \$(xdpyinfo | awk '/dimensions/{print \$2}') -i :1 -f pulse -ac 2 -i alsa_output.pci-0000_00_1f.3.analog-stereo.monitor -f pulse -ac 2 -i bluez_source.74_45_CE_96_72_00.handsfree_head_unit -filter_complex amix=inputs=2:duration=longest -vcodec libx264 -preset ultrafast -crf 0 $OUTPUT_FILE"

# Execute the FFmpeg command and capture its exit status
if $FFMPEG_CMD; then
    echo "FFmpeg command executed successfully."
else
    # If FFmpeg fails, notify the user
    notify-send "Error" "FFmpeg command failed."
    echo "FFmpeg command failed."
fi

# Remove the lock file at the end of the recording
rm "$LOCK_FILE"
echo "Lock file removed. Recording completed."

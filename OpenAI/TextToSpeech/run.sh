#!/bin/bash

server_address="localhost"
server_port="5003"  # Changed to 5003

# Function to send clipboard content to the server
send_clipboard_content() {
    # Read content from clipboard
    clipboard_content=$(xclip -o -selection clipboard)

	# Send notification with clipboard content
    notify-send "$clipboard_content"

    # Send clipboard content to the server
    echo "$clipboard_content" | nc $server_address $server_port
}

# Main logic
send_clipboard_content

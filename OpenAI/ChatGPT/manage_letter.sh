
#!/bin/bash

server_address="localhost"
server_port="5004"

# Function to send clipboard content to the server and get response
send_clipboard_content_and_get_response() {
    # Read content from clipboard
    clipboard_content=$(xclip -o -selection clipboard)

    # Send clipboard content to the server and read the response
    response=$(echo "$clipboard_content" | nc $server_address $server_port)

    # Display the response as a notification and copy it to clipboard
    echo "$response" | xargs -0 -I{} notify-send "{}"
    echo "$response" | xclip -selection clipboard
}

# Main logic
send_clipboard_content_and_get_response

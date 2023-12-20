
import socket
import threading
import requests
import pyaudio
from openai import OpenAI
import os

# Initialize OpenAI client
client = OpenAI()
api_key = os.environ.get('OPENAI_API_KEY')

# Function to handle streaming audio data
def stream_audio_data(text):
    headers = {
        'Authorization': f'Bearer {api_key}'
    }
    data = {
        'model': 'tts-1',
        'voice': 'nova',
        'input': text
    }
    response = requests.post('https://api.openai.com/v1/audio/speech', headers=headers, json=data, stream=True)

    p = pyaudio.PyAudio()
    stream = p.open(format=p.get_format_from_width(2),
                    channels=2,
                    rate=24000,
                    output=True)

    try:
        for chunk in response.iter_content(chunk_size=1024):
            if chunk:
                stream.write(chunk)
    finally:
        stream.stop_stream()
        stream.close()
        p.terminate()

def handle_client(client_socket):
    try:
        message = client_socket.recv(1024).decode()
        if message:
            print("Received message:", message)
            # Stream the audio
            stream_audio_data(message)
    finally:
        client_socket.close()

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 5003))
    server_socket.listen(1)
    print("Server listening on port 5003")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Connection from {addr}")
        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

if __name__ == "__main__":
    main()

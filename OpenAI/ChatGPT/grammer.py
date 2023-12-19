import socket
from transformers import pipeline
from openai import OpenAI

# Initialisieren des GPT-3-Modells
client = OpenAI()

def generate_response(text):
    completion = client.chat.completions.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "system", "content": "Sie sind ein Sprachassistent, der darauf spezialisiert ist, deutsche Texte zu korrigieren und zu verbessern.Du solltes nur das korriegertes Satz ausgeben. Achte auf gramatik Zeichensetugn, satzbau Wortwahl. Gebe nur das verbesser satz zuruck ohne weitern text."},
            {"role": "user", "content": text}
        ]
    )

    # Extrahieren Sie den Text der Antwort auf die korrekte Weise
    # Hier wird angenommen, dass 'message' ein Attribut des Objekts ist
    response_text = completion.choices[0].message.content
    return response_text

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 5002))
    server_socket.listen(1)
    print("Server listening on port 5002")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Connection from {addr}")

        message = client_socket.recv(1024).decode()
        if message:
            print("Received message:", message)
            response = generate_response(message)
            with open('response.txt', 'w') as f:
                f.write(response)
            client_socket.sendall(response.encode())

            client_socket.close()

if __name__ == "__main__":
    main()

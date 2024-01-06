#!/bin/bash

python3 ./ChatGPT/grammer.py &
python3 ./Whisper/record/whisper.py &
python3 /mnt/Brain/3Code/OpenAI/TextToSpeech/speech.py

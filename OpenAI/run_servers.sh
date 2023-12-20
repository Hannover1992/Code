#!/bin/bash

python3 ./ChatGPT/grammer.py &
python3 ./Whisper/record/whisper.py &
python3 ./TextToSpeech/speech.py

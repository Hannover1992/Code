#pip3 install yt-dlp
!/bin/bash

# Download the subtitles
yt-dlp --write-auto-sub --sub-lang en $1
#yt-dlp --skip-download --write-sub --sub-lang en $1


# Extract the text from the subtitle file
sed -e 's/<[^>]*>//g' *.vtt | awk '/^[0-9]+:[0-9]+:[0-9]+.[0-9]+ --> [0-9]+:[0-9]+:[0-9]+.[0-9]+/{next}1' | sed -e 's/<[^>]*>//g' > subtitles.txt

# Clean up the subtitle file
rm *.vtt

awk '!seen[$0]++' subtitles.txt > out.txt

echo "Subtitles downloaded and extracted to subtitles.txt"

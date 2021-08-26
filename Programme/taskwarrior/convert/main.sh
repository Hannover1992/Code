#read text #read text
#date=$(date | sed -e 's/\s/_/g') #get ride of _
#name=$(pwd)'/'$date'.png'
#echo $name	#get properly uniqe name
#convert -size 560x85 xc:black -font Palatino-Bold -pointsize 72 -fill white -draw ./text.txt $name	#convert input to png

convert -size 1024x1024 xc:white -font "FreeMono" -pointsize 28 -fill black -draw @ascii.txt image.png

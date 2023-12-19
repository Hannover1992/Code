#!/bin/bash

# exiftool PXL_20220426_091749267.jpg | grep "GPS Position" | cut -f2 -d":"

get_geo_location(){
	echo $1
	echo $(pwd)/$1
	exiftool $(pwd)/$1 | grep "GPS Position" | cut -f2 -d":"
#	echo $location

}

for file_name in $(ls);
	do get_geo_location $file_name;
done

for x in $(ls); do echo $x $(exiftool $x | grep "GPS Position" | cut -f2 -d":" | tr ' ' '_') ; done

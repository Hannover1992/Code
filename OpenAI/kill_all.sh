#!/bin/bash
#
for x in {5001,5002,5003}
do
	var=$(lsof -i :$x | tail -1 | awk '{print $2}')
	kill -9 $var
done

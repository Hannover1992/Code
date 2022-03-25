#!/bin/bash

for x in {1..14}; 
	do 
	task add project:uni.sigSys.vor$x vorlesung 		$x vorbereiten 			pri:7 +uni +vorbereiten 	+sigSys +vor 	+vorl 		wait:today+"$((x-2))"week week
	task add project:uni.sigSys.vor$x vorlesung 		$x nacharbeiten 		pri:7 +uni +nacharbeiten 	+sigSys +nach 	+vorl 		wait:today+"$((x-2))"week week
	task add project:uni.sigSys.ueb$x uebung 			$x vorbereiten 			pri:7 +uni +vorbereiten 		+sigSys +vor 	+ueb 		wait:today+"$((x-2))"week week
	task add project:uni.sigSys.ueb$x uebung 			$x nacharbeiten 		pri:7 +uni +nacharbeiten 		+sigSys +nach 	+ueb 		wait:today+"$((x-2))"week week

done

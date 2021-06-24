#!/bin/bash

for x in {1..14}; 
	do 
	task add project:uni.prog2.vor$x vorlesung $x vorbereiten 		pri:8 +uni +vorbereiten 	+prog2 +vor +vorl 		wait:today+"$((x-2))"week week
	task add project:uni.prog2.vor$x vorlesung $x nacharbeiten 		pri:8 +uni +nacharbeiten 	+prog2 +nach +vorl 	wait:today+"$((x-2))"week week
	task add project:uni.prog2.ueb$x uebung $x vorbereiten 			pri:8 +uni +vorbereiten 	+prog2 +vor +ueb 			wait:today+"$((x-2))"week week
	task add project:uni.prog2.ueb$x uebung $x nacharbeiten 		pri:8 +uni +nacharbeiten 	+prog2 +nach +ueb 		wait:today+"$((x-2))"week week

done


fach='sigSys'
oldPri=2
for x in {1..9};
	do
		echo $x
#		task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x vorbereiten && 
#		task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x Nacharbeiten 
#		task project:uni.$fach.hor$x \) modify pri:$oldPri$x && task \(project:uni.$fach.hau$x \) modify pri:$oldPri$x
	done

#x=10
#y=A
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x vorbereiten && 
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x Nacharbeiten && 
#
#x=11
#y=B
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x vorbereiten && 
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x Nacharbeiten && 
#
#x=12
#y=C
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x vorbereiten && 
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x Nacharbeiten && 
#
#x=13
#y=D
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x vorbereiten && 
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x Nacharbeiten && 
#
#x=14
#y=E
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x vorbereiten && 
#task add project:uni.$fach.vor$x pri:$oldPri$x Vorlesung$x Nacharbeiten && 


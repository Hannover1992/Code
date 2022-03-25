fach='sigSys'
oldPri=2
for x in {1..9};
	do
		task \(project:uni.$fach.vor$x \) modify pri:$oldPri$x && task \(project:uni.$fach.hor$x \) modify pri:$oldPri$x && task \(project:uni.$fach.hau$x \) modify pri:$oldPri$x
	done

x=10
y=A
task \(project:uni.$fach.vor$x \) modify pri:$oldPri$y 
task \(project:uni.$fach.hor$x \) modify pri:$oldPri$y
task \(project:uni.$fach.hau$x \) modify pri:$oldPri$y

x=11
y=B
task \(project:uni.$fach.vor$x \) modify pri:$oldPri$y 
task \(project:uni.$fach.hor$x \) modify pri:$oldPri$y
task \(project:uni.$fach.hau$x \) modify pri:$oldPri$y

x=12
y=C
task \(project:uni.$fach.vor$x \) modify pri:$oldPri$y 
task \(project:uni.$fach.hor$x \) modify pri:$oldPri$y
task \(project:uni.$fach.hau$x \) modify pri:$oldPri$y

x=13
y=D
task \(project:uni.$fach.vor$x \) modify pri:$oldPri$y 
task \(project:uni.$fach.hor$x \) modify pri:$oldPri$y
task \(project:uni.$fach.hau$x \) modify pri:$oldPri$y

x=14
y=E
task \(project:uni.$fach.vor$x \) modify pri:$oldPri$y 
task \(project:uni.$fach.hor$x \) modify pri:$oldPri$y
task \(project:uni.$fach.hau$x \) modify pri:$oldPri$y


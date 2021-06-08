#/bin/bash
echo "something"
#from 6 to 14
	#6 for 4 times

for x in {0..7} 
do	
	for y in {1..4}
	do
		echo $x" "$y;
		task=$((10+$x*4+$y))
		week=$((1+$x))

		echo "Task:"+$task
		echo "Week:"+$week
		#task 11 modify wait:+week
		task $task modify wait:+$week'week'
	done
done


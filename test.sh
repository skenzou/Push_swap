#!/bin/sh

if (( $# == 2 ));then
	c=$1
	e=$2
else
	c=5
	e=1
fi

sum=0
w=0
for ((;i<$c;i++));do
		ARG=`ruby -e "puts (0..$((400*e+99))).to_a.shuffle.join(' ')"`
		f=`./push_swap $ARG | wc -l`
	if ((e==1));then
		((f > 5500))&&let w++
	elif ((f>700));then
		let w++
	fi
	let sum+=f
done
echo $((sum/c))
echo "$w/$c"
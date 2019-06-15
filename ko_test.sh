#!/bin/sh
i=0

max=$1

OK_COUNT=0
KO_COUNT=0

while ((i<$max));do
	let i++
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`
	ret=`./push_swap $ARG | ./checker $ARG`
	echo $ret
	if [[ $ret = "KO" ]];then
		let KO_COUNT++
	elif [[ $ret = "OK" ]];then
		let OK_COUNT++
	fi
done

i=0

while ((i<$max));do
	let i++
	ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`
	ret=`./push_swap $ARG | ./checker $ARG`
	echo $ret
	if [[ $ret = "KO" ]];then
		let KO_COUNT++
	elif [[ $ret = "OK" ]];then
		let OK_COUNT++
	fi
done

i=0

while ((i<$max));do
	let i++
	ARG=`ruby -e "puts (-10..15).to_a.shuffle.join(' ')"`
	ret=`./push_swap $ARG | ./checker $ARG`
	echo $ret
	if [[ $ret = "KO" ]];then
		let KO_COUNT++
	elif [[ $ret = "OK" ]];then
		let OK_COUNT++
	fi
done

i=0

while ((i<$max));do
	let i++
	ARG=`ruby -e "puts (-40..153).to_a.shuffle.join(' ')"`
	ret=`./push_swap $ARG | ./checker $ARG`
	echo $ret
	if [[ $ret = "KO" ]];then
		let KO_COUNT++
	elif [[ $ret = "OK" ]];then
		let OK_COUNT++
	fi
done

i=0

while ((i<$max));do
	let i++
	ARG=`ruby -e "puts (245..375).to_a.shuffle.join(' ')"`
	ret=`./push_swap $ARG | ./checker $ARG`
	echo $ret
	if [[ $ret = "KO" ]];then
		let KO_COUNT++
	elif [[ $ret = "OK" ]];then
		let OK_COUNT++
	fi
done

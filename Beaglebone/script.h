#!/bin/bash
#GPLv3 licensed, copyright Jasper Nuyens
#available from http://www.linuxcprogramming.com
logfile=/tmp/smartdoorlog

#First we check if the gpio pin is already exported
if [[ ! -f /sys/class/gpio/gpio67/value ]]
then
echo 67 > /sys/class/gpio/export
echo in > /sys/class/gpio/gpio67/direction
fi

#Then we have the main loop - a much used shell construction
#we don't need to wait here as all waiting will happen in our C
program
while read value
do
if [[ "$value" == 0 ]]
then
echo `date` we ve got a signal >> $logfile
fi
done

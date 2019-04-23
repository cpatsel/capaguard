#!/bin/bash

#Todo: make this better
dirname=/bin/capaguard

#Make directory if not present.
mkdir $dirname 2> /dev/null

#Copy all scripts to /bin/capaguard
cp ./scripts/*.sh dirname

#Simply add the kernel module to the kernel module using insmod.
#If we want to get fancy I think modprobe would work as well.
insmod ./capa_guard.ko

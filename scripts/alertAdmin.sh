#!/bin/bash

#Argument 1: filename of snort log.

logfile=$1
admin=sysadmin
while read line; do
    if  echo "$line" | grep -q "Priority: 1"; then echo "$line" | mail -s "Critical Security Alert" ${admin}@${HOSTNAME}; fi
    if  echo "$line" | grep -q "Priority: 2"; then echo "$line" | mail -s "Security Alert" ${admin}@${HOSTNAME}; fi
done < "$logfile"

#!/bin/bash

#Runs tcpdump, rotates file every 60 seconds.
tcpdump -i enp0s8 -G 60 -w /var/log/capaguardMonitor.pcap &

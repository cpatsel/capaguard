#!/bin/bash


#run snort on monitor pcap from tcpdump. 
snort -A console -q -u snort -g snort -c /etc/snort/snort.conf -i enp0s8 -r /var/log/capaguardMonitor.pcap > /var/log/capaguardSnortResult


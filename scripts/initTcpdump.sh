#!/bin/bash

tcpdump -i enp0s8 -w /var/log/capaguardMonitor.pcap &

# capaguard
Network Intrusion Detection hub.
This is a series of systemd services and scripts that aim to help simplify the NIDS process and provide quicker more effective alerts.

First, install the dependencies below and then run the install script.

## Dependencies

```
sudo apt install tcpdump mail-utils snort*
```

## Installation

 ```bash
 sudo ./install

 ```
## Testing

Once the scripts and services are running, you can test that it is working by sending network traffic that gets picked up by snort as malicious. As an example, you can use the nmap tool to run a port scan on the host machine, where snort will, if configured properly, pick it up as a suspicious activity and mail the user defined in the alertAdmin script.

#!/bin/bash

#Todo: make this better
dirname=/bin/capaguard

#Make directory if not present.
mkdir $dirname 2> /dev/null

#Copy all scripts to /bin/capaguard
cp ./scripts/*.sh dirname



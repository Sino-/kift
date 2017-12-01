#!/usr/bin/env bash
export INET=$(ifconfig | grep "inet " | tail -1 | awk -F ' ' '{print $2}')
./kift

#!/bin/sh
if [ $(bluetoothctl show | grep "Powered: yes" | wc -c) = 0 ];then
  bluetoothctl power on
else
  bluetoothctl power off
fi

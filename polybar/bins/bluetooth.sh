#!/bin/sh
if [ $(bluetoothctl show | grep "Powered: yes" | wc -c) -eq 0 ]
then
  echo "%{F#7c6f64}"
else
  if [ $(echo info | bluetoothctl | grep 'Device' | wc -c) -eq 0 ]
  then 
    echo ""
  else
    NAME="$(echo info | bluetoothctl | grep 'Alias:' | awk -F:  '{ print $2 }')"
    #echo "%{F#458588}$NAME"
    echo "%{F#458588}"
  fi
fi


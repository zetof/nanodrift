#!/bin/bash

if [ -z "$1" ]; then
  echo "No argument supplied"
elif [ "$1" = "uno" ]; then
  MICRO="arduino:avr:uno"
  USB="ttyACM0"
elif [ "$1" = "nano" ]; then
  MICRO="atmel-avr-xminis:avr:atmega328p_xplained_mini"
  USB="ttyUSB0"
else
  echo "Valid arguments are 'uno' or 'nano'"
fi

if [ ! -z "${MICRO}" ]; then
  if arduino-cli compile --fqbn $MICRO ./; then
    arduino-cli upload -p /dev/$USB --fqbn $MICRO ./
    arduino-cli monitor -p /dev/$USB --config 9600
  fi
fi

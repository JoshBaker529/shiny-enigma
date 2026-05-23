#!/bin/bash

# This file is a helper script for adding a header to a file
# Wrapper for writing to a binary file

if [ $# -le 2 ]; then
  echo "Usage: ./write_bin.sh <file> [{Hex}]"
fi

for arg in "${@:2}"; do
  printf "\x$arg" >>$1
done

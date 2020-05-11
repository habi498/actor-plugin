#!/bin/bash

cd geoip-api-c
make clean
./bootstrap > /dev/null
CFLAGS=$@ ./configure --with-pic > /dev/null
CFLAGS=$@ make
cd ..

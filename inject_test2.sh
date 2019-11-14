#!/bin/bash
./inject libevil.so test
sudo cp libevil.so /lib/x86_64-linux-gnu/
sudo ldconfig


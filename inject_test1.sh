#!/bin/bash
./inject liblogger.so test
sudo cp liblogger.so /lib/x86_64-linux-gnu/
sudo ldconfig


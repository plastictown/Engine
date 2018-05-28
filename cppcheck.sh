#!/bin/bash
cppcheck --enable=all --inconclusive --language=c++ --platform=unix32 --std=c++11 -I/usr/include -I./include/ .

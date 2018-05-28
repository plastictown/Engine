#!/bin/bash
cppcheck --enable=all --language=c++ --platform=unix32 --std=c++11 -v -I./include/ .

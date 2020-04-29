@echo off

cls
g++ %1.cpp -o %1.exe && %1.exe < input.in > output.out
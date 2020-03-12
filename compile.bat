@echo off

cls
g++ %1.cpp -o %1.exe -DDEBUG

if %ERRORLEVEL% EQU 0 (
	%1.exe
)
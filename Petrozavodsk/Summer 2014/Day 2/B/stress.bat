@echo off

:start

gen.exe
B.exe > out
stupid.exe > tmp.out
fc out tmp.out
if ERRORLEVEL 1 goto end
goto start
:end
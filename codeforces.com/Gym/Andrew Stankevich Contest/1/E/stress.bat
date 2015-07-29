@echo off
:start
gen.exe
Main.exe
Main1.exe
fc nice.out zarlyk.out
if ERRORLEVEL 1 pause
goto start
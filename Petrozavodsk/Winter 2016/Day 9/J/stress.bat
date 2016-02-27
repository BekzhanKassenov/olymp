@echo off
:start
gen > in
Main
if errorlevel 1 goto end
goto start
:end
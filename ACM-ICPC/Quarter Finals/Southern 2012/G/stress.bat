@echo off

:start
gen
Main
stup
fc output.txt stup.txt
if errorlevel 1 goto end
goto start
:end



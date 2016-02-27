@echo off
:start
gen > in
Main > Main.out
stup > stup.out

fc Main.out stup.out
if errorlevel 1 goto end
goto start
:end
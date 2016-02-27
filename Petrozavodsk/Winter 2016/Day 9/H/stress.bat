@echo off
:start
gen > in
Main > Main.out
correct > correct.out
fc Main.out correct.out
if errorlevel 1 goto end
goto start
:end
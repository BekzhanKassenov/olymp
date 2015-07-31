@echo off
:start
gen > in
D > out
stup > stup.out
fc out stup.out
if errorlevel 1 goto end
goto start
:end
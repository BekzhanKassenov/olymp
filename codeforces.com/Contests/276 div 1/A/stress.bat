:start
gen.exe
A.exe > out
stup.exe > stup.out
fc out stup.out
if ERRORLEVEL 1 goto end
goto start
:end
:starting
gen.exe
B.exe

copy out tmp.out

test.exe

fc out tmp.out

if ERRORLEVEL 1 goto ending
goto starting
:ending


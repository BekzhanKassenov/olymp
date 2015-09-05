:starting
gen.exe
slow.exe

copy out tmp.out

fast.exe

fc out tmp.out

if ERRORLEVEL 1 goto ending

goto starting

:ending
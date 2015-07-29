:starting

gen_test.exe

D.exe

copy out tmp.out

slow.exe

fc out tmp.out

if ERRORLEVEL 1 goto ending

goto starting

:ending

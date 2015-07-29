g++ test.cpp -o test.exe
g++ gen.cpp -o gen.exe
g++ c.cpp -o c.exe

:starting
gen.exe
c.exe
copy out tmp.out
test.exe
fc out tmp.out
if ERRORLEVEL 1 goto ending
goto starting
:ending

g++ fenwick.cpp -o fenwick.exe
g++ gen.cpp -o gen.exe
g++ 1316.cpp -o 1316.exe
:starting
gen.exe
1316.exe
copy out tmp.out
fenwick.exe
fc out tmp.out
if ERRORLEVEL 1 goto ending
goto starting
:ending
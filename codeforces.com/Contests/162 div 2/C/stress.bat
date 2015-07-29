g++ C.cpp -o C.exe -O2 -Wextra
g++ gen.cpp -o gen.exe -O2 -Wextra
g++ slow.cpp -o slow.exe -O2 -Wextra

:starting
gen.exe

C.exe

copy out tmp.out

slow.exe

fc out tmp.out

if ERRORLEVEL 1 goto ending

goto starting

:ending


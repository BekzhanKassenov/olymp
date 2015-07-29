g++ C.cpp -o C.exe
if ERRORLEVEL 1 goto end
g++ new_C.cpp -o new_C.exe
if ERRORLEVEL 1 goto end
g++ gen.cpp -o gen.exe
if ERRORLEVEL 1 goto end

:start
gen.exe
C.exe
copy sum.out tmp.out
new_C.exe
fc sum.out tmp.out
if ERRORLEVEL 1 goto end
goto start
:end


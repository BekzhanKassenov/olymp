g++ 77.cpp -o 77.exe
if ERRORLEVEL 1 goto end

g++ gen.cpp -o gen.exe
if ERRORLEVEL 1 goto end

g++ test.cpp -o test.exe
if ERRORLEVEL 1 goto end

:beg
gen.exe
test.exe
copy output.txt tmp.out
77.exe
fc output.txt tmp.out
if ERRORLEVEL 1 goto end
goto beg

:end


g++ G1.cpp -o G1.exe
g++ gen.cpp -o gen.exe
g++ tup.cpp -o tup.exe
:start
gen.exe
tup.exe
copy out tmp.out
G1.exe
fc out tmp.out
if ERRORLEVEL 1 goto end
goto start
:end


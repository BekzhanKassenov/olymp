@echo off

g++ E1.cpp -o E1.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall
if ERRORLEVEL 1 goto end

g++ slow.cpp -o slow.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
if ERRORLEVEL 1 goto end

g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
if ERRORLEVEL 1 goto end

:start
gen.exe
slow.exe
copy sparse.out tmp.out
E1.exe
fc sparse.out tmp.out
if ERRORLEVEL 1 goto end
goto start
:end

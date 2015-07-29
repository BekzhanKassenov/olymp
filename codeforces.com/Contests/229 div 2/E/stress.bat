cls

@echo off

@echo Compilation...
g++ E.cpp -o E.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ stupid.cpp -o stupid.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
@echo Compiled.

:cycle
@echo Generating
gen.exe
@echo Generated

@echo E.exe
E.exe > out

@echo stupid.exe
stupid.exe > out1

fc out out1
if errorlevel 1 goto end

goto cycle

:end
@echo Error

cls

@echo off

@echo Compiling...

g++ clear_file.cpp -o clear_file.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
if ERRORLEVEL 1 goto end

g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
if ERRORLEVEL 1 goto end

g++ set.cpp -o set.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
if ERRORLEVEL 1 goto end

g++ set_from_vec.cpp -o set_from_vec.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
if ERRORLEVEL 1 goto end

g++ unique.cpp -o unique.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
if ERRORLEVEL 1 goto end

@echo Compilation finished

clear_file.exe

:start

@echo ---------------------

gen.exe
@echo Generated

set.exe
@echo Set

set_from_vec.exe
@echo Set from vec

unique.exe
@echo Unique

if ERRORLEVEL 1 goto end
goto start
:end
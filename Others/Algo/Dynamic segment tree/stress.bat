cls

@echo off

@echo Compilation...
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ Main.cpp -o Main.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ stupid.cpp -o stupid.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal

@echo Compilation finished

:start

@echo -----------------------

gen.exe > in.txt
Main.exe > Main.out < in.txt 
stupid.exe > stupid.out < in.txt

fc Main.out stupid.out

if ERRORLEVEL 1 (
    @echo ERROR!
    goto end
)

goto start
:end

cls
@echo off

@echo Compilation started
g++ E.cpp -o E.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ right.cpp -o right.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ check.cpp -o check.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal

:start
@echo -------------------
@echo Generation...
gen.exe
@echo E
E.exe > out1
@echo right
right.exe > out2
@echo Checking...

if ERRORLEVEL 1 (
    @echo WA
    goto end
)

if ERRORLEVEL 2 (
    @echo DIFFERENT NUMBER OF LINES
    goto end
)

@echo OK
goto start

:end
@echo Finishing

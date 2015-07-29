@echo off
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ AC_sol.cpp -o AC_sol.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ test_sol.cpp -o test_sol.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal

:start
gen.exe
AC_sol.exe > out
test_sol.exe > tmp.out
fc out tmp.out
if ERRORLEVEL 1 goto end
goto start
:end

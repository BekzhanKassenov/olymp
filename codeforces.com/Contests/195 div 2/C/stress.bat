g++ C.cpp -o C.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall -DLocal
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall -DLocal
g++ new_c.cpp -o new_c.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall -DLocal

:start
gen.exe
C.exe
copy out tmp.out
new_c.exe
fc out tmp.out
if ERRORLEVEL 1 goto end
goto start
:end


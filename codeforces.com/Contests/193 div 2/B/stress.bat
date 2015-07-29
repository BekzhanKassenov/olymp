g++ B.cpp -o B.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall -DLocal
g++ slow.cpp -o slow.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall -DLocal
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall -DLocal

:start
gen.exe
B.exe
copy out tmp.out
slow.exe
fc out tmp.out
if ERRORLEVEL 1 goto end
goto start
:end

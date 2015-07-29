g++ J.cpp -o J.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ test.cpp -o test.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ good.cpp -o good.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal

:start
test.exe
J.exe
good.exe
fc out out1
if ERRORLEVEL 1 goto end
goto start
:end

@echo off
@echo Compiling...

g++ fenwick.cpp -o fenwick.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ tested.cpp -o tested.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal

@echo Compilation completed

if errorlevel 1 (
	@echo Compilation error!
	goto end
)

:start
@echo =========================================
gen > in
fenwick > fenwick.out < in
tested > tested.out < in
fc fenwick.out tested.out
if errorlevel 1 (
 	@echo WA
 	goto end
)
@echo OK!
goto start
:end


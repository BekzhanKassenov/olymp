cls
@echo off

@echo Compilation started...
g++ 1553.cpp -o 1553.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ hld_treap.cpp -o hld_treap.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -Wl,--stack=268435456 -O2 -Wextra -Wall -DLocal

if errorlevel 1 goto error

@echo Compilation finished successfully

:start_cycle 

@echo ------------------------------

@echo Generating...
gen.exe

@echo 1553...
1553.exe > out

@echo hld_treap...
hld_treap.exe > tmp.out

fc out tmp.out

if errorlevel 1 goto error

goto start_cycle

:error
@echo ERROR OCCURED!!!
goto end

:end
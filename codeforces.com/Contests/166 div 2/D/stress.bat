g++ D.cpp -o D.exe
g++ right_solution.cpp -o right_solution.exe
g++ gen.cpp -o gen.exe

:begin
gen.exe
D.exe
copy out tmp.out
righ_solution.exe
fc out tmp.out
if ERRORLEVEL 1 goto end
goto begin
:end
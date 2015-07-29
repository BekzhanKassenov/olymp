:begin
gen.exe
A.exe
copy out tmp.out
test.exe
fc out tmp.out
if ERRORLEVEL 1 goto end
goto begin
:end

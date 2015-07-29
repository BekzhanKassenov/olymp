:start
gen.exe
160.exe
copy output.txt tmp.txt
160_min.exe
fc output.txt tmp.txt
if ERRORLEVEL 1 goto end
goto start
:end

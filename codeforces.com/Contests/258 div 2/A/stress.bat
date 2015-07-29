:start 
gen.exe
A.exe > out
lol.exe > tmp.out
fc out tmp.out
if ERRORLEVEL 1 (
@echo ERROR
goto end
)
@echo OK
:end

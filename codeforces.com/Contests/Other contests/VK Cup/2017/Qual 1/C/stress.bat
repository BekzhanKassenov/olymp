:start
gen 12 > in
C > C.out
stup > stup.out
fc C.out stup.out
if errorlevel 1 goto end
goto start
:end
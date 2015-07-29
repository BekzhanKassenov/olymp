:start
gen > in
A > A.out < in
stup > stup.out < in
fc A.out stup.out
if errorlevel 1 goto end
goto start
:end
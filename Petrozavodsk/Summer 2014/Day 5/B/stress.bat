@echo off
:start
    gen.exe > in
    Main.exe > out
    stup.exe  > stup.out < in
    fc out stup.out
    if errorlevel 1 goto end
    goto start
:end

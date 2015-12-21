@echo off

:start
    gen > in
    Main > Main.out < in
    stup > stup.out < in

    fc Main.out stup.out

    if errorlevel 1 goto end

    goto start
:end
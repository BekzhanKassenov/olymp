@echo off
:start
    gen > in
    B > B.out
    stup > stup.out
    fc B.out stup.out
    if ERRORLEVEL 1 goto end
    goto start
:end
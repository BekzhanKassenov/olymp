:start
    D > D.out
    stup > stup.out

    fc D.out stup.out

    if errorlevel 1 goto end
    goto start

:end
cl.exe *.cpp  /O2 /W2 /EHsc  /Zi /c  /I..  /D _CRT_SECURE_NO_DEPRECATE
if errorlevel 1 goto exit
lib.exe /out:GameLogic.lib *.obj ..\LUA\*.obj ..\Common\*.obj
if errorlevel 1 goto exit

:exit
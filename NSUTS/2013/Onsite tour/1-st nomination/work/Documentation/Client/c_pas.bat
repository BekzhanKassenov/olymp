if [%1]==[] exit(1)
set PASCALDLLNAME=%1

pushd Pas
    fpc -O2 Api.pp
    if errorlevel 1 exit(2)
popd
cl.exe *.cpp Pas\AdapterPas.cpp ..\Common\*.obj  /O2 /W2 /EHsc  /Zi  /I..  /Fe"Client.exe"  /D PASCALDLL=%PASCALDLLNAME%   /D _CRT_SECURE_NO_DEPRECATE
if errorlevel 1 exit(3)
copy Pas\Api.dll %PASCALDLLNAME%.dll

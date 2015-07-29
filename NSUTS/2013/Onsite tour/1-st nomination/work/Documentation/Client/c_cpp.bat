pushd Cpp
    cl.exe Solution.cpp  /O2 /W2 /EHsc  /Zi  /c   /D _CRT_SECURE_NO_DEPRECATE
    if errorlevel 1 exit(1)
popd
cl.exe *.cpp Cpp\Solution.obj ..\Common\*.obj  /O2 /W2 /EHsc  /Zi  /I..  /Fe"Client.exe"   /D _CRT_SECURE_NO_DEPRECATE
if errorlevel 1 exit(2)

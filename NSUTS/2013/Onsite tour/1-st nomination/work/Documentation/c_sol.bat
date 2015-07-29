@echo off
call __set_java_home.bat

if [%1]==[] (
    echo Specify solution file as the first parameter!
    goto Exit
)
if [%~x1]==[.cpp] (
    copy %1 Client\Cpp\Solution.cpp
    pushd Client
        call w.bat
        call c_cpp.bat
        move Client.exe %~pn1.exe
    popd
    del Client\Cpp\Solution.cpp
    goto Exit
)

if [%~x1]==[.pas] (
    copy %1 Client\Pas\Solution.pas
    pushd Client
        call w.bat
        call c_pas.bat %~n1
        move Client.exe %~pn1.exe
        move %~n1.dll %~pn1.dll
    popd
    del Client\Pas\Solution.pas
    goto Exit
)

if [%~x1]==[.java] (
    copy %1 Client\Java\%~n1.java
    pushd Client
        call w.bat
        call c_java.bat %~n1
        move Client.exe %~pn1.exe
        move *.class %~p1
    popd
    goto Exit
)

echo Unknown extension "%~x1"

:Exit

@echo off
call __set_java_home.bat
@set path=%JAVA_HOME%\jre\bin\server;%CD%\SimpleVis;%path%

if [%1]==[] goto FormatExplanation
if [%2]==[] goto FormatExplanation

set PARAM1=%1
set PARAM2=%2

if [%~x1]==[.exe] (
    set CL_A="%PARAM1:~0,-4%.exe %~n1.lua"
) else (
    set CL_A=%1
)
if [%~x2]==[.exe] (
    set CL_B="%PARAM2:~0,-4%.exe %~n2.lua"
) else (
    set CL_B=%2
)

del *.txt

echo Client A: %CL_A%
echo Client B: %CL_B%
echo Options: %4 %5 %6 %7 %8 %9

%3 %CL_A% %CL_B% %4 %5 %6 %7 %8 %9
goto Exit

:FormatExplanation
echo Usage examples:
echo   1. Specify two command lines for solutions:
echo     run.bat "SolutionA.exe SolutionA.lua" "SolutionB.exe SolutionB.lua"  {...}
echo   2. Specify two solution exe-files (lua files must have same names):
echo     run.bat SolutionA.exe SolutionB.exe  {...}
echo {...} means any additional parameters for the server (not required).

:Exit

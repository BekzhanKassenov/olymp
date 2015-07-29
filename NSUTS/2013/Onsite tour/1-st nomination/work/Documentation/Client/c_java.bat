if [%1]==[] exit(1)
set CLASSNAME=%1

pushd Java
    "%JAVA_HOME%\bin\javac" -XDignore.symbol.file *.java
    if errorlevel 1 exit(2)
popd
cl.exe *.cpp Java\AdapterJava.cpp ..\Common\*.obj "%JAVA_HOME%\lib\jvm.lib"  /O2 /W2 /EHsc  /Zi  /I.. /I"%JAVA_HOME%\include" /I"%JAVA_HOME%\include\win32"  /Fe"Client.exe"  /D CLASSNAME=%CLASSNAME%   /D _CRT_SECURE_NO_DEPRECATE
if errorlevel 1 exit(3)
copy Java\*.class *.class

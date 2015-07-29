cl test.cpp *.cpp "%JAVA_HOME%\lib\jvm.lib"  /O2 /W2 /EHsc  /Zi  -I ../../ -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32"
"%JAVA_HOME%\bin\javac" -XDignore.symbol.file *.java

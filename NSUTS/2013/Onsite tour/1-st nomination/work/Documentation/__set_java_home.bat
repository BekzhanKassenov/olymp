if exist "C:\Program Files\Java\jdk1.6.0_27\bin\javac.exe" (
	rem echo x32
	set JAVA_HOME="C:\Program Files\Java\jdk1.6.0_27"
)
if exist "C:\Program Files (x86)\Java\jdk1.6.0_27\bin\javac.exe" (
	rem echo x64
	set JAVA_HOME="C:\Program Files (x86)\Java\jdk1.6.0_27"
)
set JAVA_HOME=%JAVA_HOME:"=%

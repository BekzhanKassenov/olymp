@echo off
:L
	gen.exe > input
	sqrt.exe > output.ans
	tree.exe > output
	fc output.ans output
	if errorlevel 1 goto end
goto L
:end
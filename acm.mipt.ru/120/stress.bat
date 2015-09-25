@echo off

:start
	gen > in
	test < in > test.out
	stl < in > stl.out
	fc test.out stl.out
	if errorlevel 1 goto end
	goto start
:end
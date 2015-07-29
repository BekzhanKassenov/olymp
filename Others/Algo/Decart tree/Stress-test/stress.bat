g++ Main.cpp -o Main.exe -O2
g++ Main1.cpp -o Main1.exe -O2
g++ Main2.cpp -o Main2.exe -O2
g++ gen.cpp -o gen.exe -O2
g++ clear_file.cpp -o clear_file.exe

clear_file.exe

:start
gen.exe
Main.exe
Main1.exe
Main2.exe
goto start

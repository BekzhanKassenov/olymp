g++ Main.cpp -o Main.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall
g++ Main_array.cpp -o Main_array.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall
g++ stl.cpp -o stl.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall
g++ gen.cpp -o gen.exe -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -Wextra -Wall
g++ clear_file.cpp -o clear_file.exe
clear_file.exe

:start
gen.exe
stl.exe
Main.exe
Main_array.exe
goto start
:end
del tmp.out

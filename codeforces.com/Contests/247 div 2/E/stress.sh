echo Compilation started
g++ E.cpp -o E.exe -DLocal
g++ right.cpp -o right.exe -DLocal
g++ gen.cpp -o gen.exe -DLocal
g++ check.cpp -o check.exe -DLocal

for i in {1..1000}
do
    echo $i
    ./gen.exe
    ./E.exe > out1
    ./right.exe > out2
    ./check.exe || exit
done

echo "OK"
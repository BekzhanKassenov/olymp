#include <fstream>

int s, a, z;

main() {
    std :: ofstream q("output.txt");
    
    for (std :: ifstream f("input.txt"); f >> a >> z;)
        s += a - z;
    
    if (s) 
        q << 2 - (s > 0);
    else
        q << "DRAW";
}

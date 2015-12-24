#include <iostream>
 
int s, a, z;
 
main() {
    for (; std::cin >> a >> z;)
        s += a - z;
     
    if (s) 
        std::cout << 2 - (s > 0);
    else
        std::cout << "DRAW";
}
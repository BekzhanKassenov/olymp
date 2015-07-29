#include <fstream>
#include <algorithm>

__int64 s, n, a[10010], *p = a;

main() {   
    std :: ifstream q("input.txt");

    for (q >> n; p < a + n;)
        q >> *p++; 

    std :: sort(a, p);

    for (p = a; *p - s < 2 && n--; s += *p++);
     
    std :: ofstream ("output.txt") << s + 1;
}

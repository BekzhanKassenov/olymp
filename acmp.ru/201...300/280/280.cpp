#include <fstream>

__int64 n, i = 2, r = 1, a;  

main() {
    std :: ifstream("input.txt") >> n;

    for (; n > 1; r *= a + !a, i++)
        for (a = 0; n % i == 0; n /= i)
            a++;
                                          
    std :: ofstream("output.txt") << r;
}


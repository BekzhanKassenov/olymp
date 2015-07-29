#include <fstream>

int n, w[10010], i = 1;

main() {
    for (std :: ifstream ("input.txt") >> n; i <= n; i++)
        w[i] = !w[i - 1] | i > 1 & !w[i - 2] | i > 999 & !w[i - 1000];

    std :: ofstream ("output.txt") << 2 - w[n];
}

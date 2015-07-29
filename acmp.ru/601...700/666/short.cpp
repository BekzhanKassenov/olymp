#include <fstream>

int n, l = (1 << 26) - 1, r = 'z';

main() {
    for (std :: fstream ("input.txt") >> n, n--; n--; std :: ofstream ("output.txt").put(--r))
        n %= l /= 2;
}

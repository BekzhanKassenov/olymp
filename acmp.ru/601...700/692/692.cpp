#include <fstream>

int n;

main() {
    std :: ifstream("input.txt") >> n;

    std :: fstream o("output.txt");

    o << (n <= 0 || n & (n - 1) ? "NO" : "YES");
}

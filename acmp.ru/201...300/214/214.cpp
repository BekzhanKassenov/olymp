#include <fstream>

int n, m;

main()
{
    std :: fstream ("input.txt") >> n >> m;
    std :: ofstream ("output.txt") << ((n ^ m) ? 1 : 2);
}

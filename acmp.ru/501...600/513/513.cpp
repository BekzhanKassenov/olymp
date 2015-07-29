#include <fstream>

int n;

main()
{
	std :: fstream ("input.txt") >> n;
	std :: ofstream ("output.txt") << (1 << n) - n - 1;
}
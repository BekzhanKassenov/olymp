#include <fstream>

int n, f, a = 1, b;

main()
{
	std :: ifstream i ("input.txt");
	
	for (i >> n; n--; b = a, a = f)
		f = a + b;

	std :: ofstream ("output.txt") << b;
}

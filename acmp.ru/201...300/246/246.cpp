#include <fstream>

int x, y, a;

main()
{
	std :: fstream i ("input.txt");
	
	for (i >> x >> x; i >> y; x = y)
		a += y != x + 1;

	std :: ofstream ("output.txt") << a;
}

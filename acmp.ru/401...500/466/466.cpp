#include <fstream>

int f(int n)
{
	if (n == 0 | n == 1)
		return n;

	return f(n / 2) + ((n % 2) ? f(n / 2 + 1) : 0);
}

int n;

main()
{
	std :: fstream ("input.txt") >> n;
	std :: ofstream ("output.txt") << f(n);
}

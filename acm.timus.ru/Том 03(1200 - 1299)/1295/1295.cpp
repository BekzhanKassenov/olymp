#include <cstdio>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	if ((n - 5) % 20 == 0)
		{
			puts("2");
			return 0;
		}

	if (n % 4 == 0)
		{
			puts("0");
			return 0;
		}
	if (n % 4 == 1 || n % 4 == 2)
		{
			puts("1");
			return 0;
		}


	puts("2");
	return 0;
}


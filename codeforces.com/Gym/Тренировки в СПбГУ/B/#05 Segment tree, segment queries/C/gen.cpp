#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("sum.in", "w", stdout);

	srand(time(NULL));

	int n = 1 + rand() % 100;
	int m = rand() % 20;

	cout << n << ' ' << m << endl;

	for (int i = 0; i < m; i++)
		{
			int l = rand() % n;

			int r = l + rand() % (n - l);

			if (rand() & 1)
				printf("A %d %d %d\n", l + 1, r + 1, rand());
			else
				printf("Q %d %d\n", l + 1, r + 1);
		}

	return 0;	
}

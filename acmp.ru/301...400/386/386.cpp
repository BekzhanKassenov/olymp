#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	puts("YES");

	for (int i = -160; i <= 160; i++)
		{
			cout << i << ' ' << (i * (i - 1)) / 2 - 10000 << endl;

			n--;

			if (!n)
				break;
		}

	return 0;
}

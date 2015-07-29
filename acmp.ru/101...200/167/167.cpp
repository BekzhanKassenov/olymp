#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long n;

	cin >> n;

	n = (n * (n + 2) * (2 * n + 1));

	printf("%.0f", (n + .0) / 8.0);

	return 0;
}

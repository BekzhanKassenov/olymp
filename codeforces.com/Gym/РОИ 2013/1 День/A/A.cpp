#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("casting.in", "r", stdin);
	freopen("casting.out", "w", stdout);

	int a, b, c;

	int n, k;

	cin >> k >> n;

	cin >> a >> b >> c;

	if (k == 2)
		cout << max(min(min(a, b), c), 0);

	else
		cout << max(0, a + b + c - 2 * n);

	return 0;
}

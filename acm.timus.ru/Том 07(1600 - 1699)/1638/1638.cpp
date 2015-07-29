#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b, c, d;

	cin >> a >> b >> c >> d;

	if (c == d)
		{
			cout << a;

			return 0;
		}

	cout << abs((d - c) * b * 2 + (d - c - 1) * a);

	return 0;
}

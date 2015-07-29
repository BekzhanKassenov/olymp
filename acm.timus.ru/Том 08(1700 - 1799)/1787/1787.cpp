#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int k, n;

	cin >> k >> n;

	int now = 0;

	for (int i = 0; i < n; i++)
		{
			int tmp;

			cin >> tmp;

			now += tmp;

			now = (k < now) ? (now - k) : 0;
		}

	cout << now;
}

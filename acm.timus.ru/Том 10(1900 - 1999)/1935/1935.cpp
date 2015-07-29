#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int x;

	int sum = 0;

	int mx = 0;

	for (int i = 0; i < n; i++)
		{
			cin >> x;
			sum += x;
			mx = max(mx, x);
		}

	sum += mx;

	cout << sum;

	return 0;
}

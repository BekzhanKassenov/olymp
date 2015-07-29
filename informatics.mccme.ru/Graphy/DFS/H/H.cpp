#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> st(n);

	int x, y;

	for (int i = 0; i < n - 1; i++)
		{
			cin >> x >> y;

			st[--x]++, st[--y]++;
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
		if (st[i] > 1)
			ans++;

	cout << ans;

	return 0;
}

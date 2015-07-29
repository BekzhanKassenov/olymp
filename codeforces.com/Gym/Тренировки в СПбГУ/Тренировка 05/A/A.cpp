#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("stupid_rmq.in", "r", stdin);
	freopen("stupid_rmq.out", "w", stdout);

	int n;
	
	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int m;

	cin >> m;

	int l, r;

	for (int i = 0; i < m; i++)
		{
			cin >> l >> r;

			l--, r--;

			int ans = (int)2e9;

			for (int j = l; j <= r; j++)
				ans = min(ans, a[j]);

			cout << ans << endl;	
		}

	return 0;
}

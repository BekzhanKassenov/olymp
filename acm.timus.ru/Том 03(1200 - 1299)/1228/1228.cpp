#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, s;
	
	cin >> n >> s;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> ans(n, 0);

	s--;

	for (int i = 0; i < n; i++)
		{
			ans[i]++;
			s -= a[i];
		}

	for (int i = 0; i < n; i++)
		{
			ans[i] += s / a[i];
			s %= a[i];
		}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}

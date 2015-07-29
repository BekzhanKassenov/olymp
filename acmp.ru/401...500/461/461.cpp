#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int cnt = (n >> 1) + 1;

	int ans = 0;

	for (int i = 0; i < cnt; i++)
		ans += (a[i] >> 1) + 1;

	cout << ans;

	return 0;	
}

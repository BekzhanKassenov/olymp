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

	vector <int> a(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector <int> ans(n + 1);

	for (int i = 1; i <= n; i++)
		ans[a[i]] = i;

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ' ;

	return 0;
}

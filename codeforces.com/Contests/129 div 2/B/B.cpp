#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	//freopen("in","r",stdin);
	int n;
	cin >> n;
	vector <int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
			cin >> a[i];

	long long ans = 0;
	
	for (int i = 1; i < n; i++)
		if (a[i] > a[i + 1])
			ans += (a[i] - a[i + 1]);

	cout << ans;
	return 0;
}

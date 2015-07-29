#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for (int a = 0; a <= n + m; a++)
		for (int b = 0; b <= n + m; b++)
			if ((a * a) + a + b + (b * b) == n + m && a * a + b == n && a + b * b == m)
				ans++;
	cout << ans;
	return 0;
}

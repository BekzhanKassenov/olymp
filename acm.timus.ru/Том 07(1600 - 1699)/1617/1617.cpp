#include <iostream>
#include <cstdio>

using namespace std;

int a[101];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			int tmp;

			cin >> tmp;

			a[tmp - 600]++;
		}

	int ans = 0 ;

	for (int i = 0; i < 101; i++)
		ans += a[i] / 4;

	cout << ans;	
}

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	vector <int> a(100000);

	a[0] = 0;

	a[1] = 1;

	for (int i = 0; i < 100000; i++)
		{
			if (2 * i < 100000)
				a[2 * i] = a[i];

			else
				break;

			if (2 * i + 1 < 100000)
				a[2 * i + 1] = a[i] + a[i + 1];
		}

	int n;

	cin >> n;

	while (n)
		{
			int ans = 0;	

			for (int i = 0; i <= n; i++)
				ans = max(a[i], ans);
			
			cin >> n;

			cout << ans << endl;
		}

 	return 0;	
}

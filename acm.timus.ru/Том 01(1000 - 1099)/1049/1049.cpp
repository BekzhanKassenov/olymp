#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int d[10];
	
	int a = 5;

	for (int i = 0; i < 10; i++)
		cin >> d[i];

	int cnt[10001] = {0};

	for (int i = 0; i < 10; i++)
		{
			for (int k = 2; k <= 10000; k++)
				{
					while (d[i] % k == 0)
						{
							d[i] /= k;
							cnt[k]++;
						}
				}
		}


	int ans = 1;

	for (int i = 0; i < 10001; i++)
		{
			if (cnt[i] > 0)
				{
					ans = (ans * (cnt[i] + 1)) % 10;
				}
		}

	cout << ans;
}

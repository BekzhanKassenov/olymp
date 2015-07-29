#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	map <int, int> m;

	for (int i = 0; i < n; i++)
		{
		   int tmp;

		   scanf("%d", &tmp);

			m[tmp]++;
		}

	int ans1 = 0, ans2 = 0;

	for (map <int, int> :: iterator it = m.begin(); it != m.end(); it++)
		{
			if (it -> second > ans1)
				{
					ans1 = it -> second;
					ans2 = it -> first;
				}
		}

	cout << ans2;	
}

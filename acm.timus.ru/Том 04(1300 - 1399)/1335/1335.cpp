#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	if (n == 0)
		{
			cout << "NO SOLUTION";
			return 0;
		}

	int ans1 = -1, ans2 = -1;

	for (int i = n * n + 1; i <= (n + 1) * (n + 1); i++)
		{
			if (i % n == 0)
				{
					if (ans1 == -1)
						{
							ans1 = i;
						}
					else
						{
							if (ans2 == -1)
								ans2 = i;
							else
								break;	
						}
				} 
		}

	cout << ans1 << ' ' << ans2 << ' ' << n * n;

	return 0;
}

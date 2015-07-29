#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	if (m == 1)
		{
			cout << n;
			return 0;
		}
	
	int ans = 0;

	while (true)
		{
			if (!n)
				break;

			if (m & 1)
				{
					ans += (n >> 1);
					n = (n >> 1) + (n & 1);
					m >>= 1;
					m++;
				}
			else
				{
					ans += m >> 1;
					break;
				}
		}
	cout << ans;
	return 0;	
}

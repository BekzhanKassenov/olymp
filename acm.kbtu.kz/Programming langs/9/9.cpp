#include <iostream>
#include <cmath>

using namespace std;

int sum(int n)
{
	int ans = 0;
	for (int i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
				{
					ans += i;
					if (i * i != n)
						ans += (n / i);
				}
		}
	return ans;
}

int main()
{
	int n;
	cin >> n;  
	int mc = 0, c, ans = 1;
	for (int i = 1; i <= n; i++)
		{
			c = sum(i);
			if (c > mc)
				{
					mc = c;
					ans = i;
				}
		}
	cout << ans;
	return 0;
}
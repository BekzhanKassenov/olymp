#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define int long long

int gcd (int a, int b) 
{
	if (a == 1 || b == 1)
		return 1;

	if (a == b)
		return a;

	if (a == 0 || b == 0)
		return a + b;

	if (a < b)
		return gcd(a, b % a);
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	int ans = (b / gcd(a, b)) * a;
	return ans;
}

main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int ans = 1;

	for (int i = 2; i <= n; i++)
		{
			ans = lcm(ans, i);

			if (ans > 1000000000)
				{
					cout << "OK" << endl;
					break;
				}
			cout << i << ' ' << ans << endl;
		}

	cout << ans;
}
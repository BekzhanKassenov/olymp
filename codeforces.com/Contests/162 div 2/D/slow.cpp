#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector <int> a;

int n;

int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;

	if (a > b)
		return gcd(a % b, b);
	else
		return gcd(b % a, a);	
}

int slow()
{
	int ans = 0;
	for (int mask = 1; mask < (1 << n); mask++)
		{
			vector <int> tmp;

			for (int i = 0; i < n; i++)
				{
					if (mask & (1 << i))
						tmp.push_back(a[i]);
				}


			bool flag = true;

			for (int i = 1; i < (int)tmp.size(); i++)
				if (gcd(tmp[i], tmp[i - 1]) == 1)
					flag = false;

			if (flag)
				ans = max(ans, (int)tmp.size());
		}

	return ans;
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	cin >> n;

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << slow() << endl;

	return 0;	
}

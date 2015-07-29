#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define long long ll

bool prime(int n)
{
	if (n == 1)
		return false;

	int k = (int) sqrt(n + .0);

	for (int i = 2; i <= k; i++)
		if (n % i == 0)
			return false;

  	return true;
}

int a[1001];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n;

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			if (prime(i))
				{
					while (n % i == 0)
						{
							n /= i;
							a[i]++;
						}
				}
		}


}

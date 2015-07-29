#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[8];

int g[8][8];

bool prime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;	
}

int next_prime(int n)
{
	for (int i = n + 1; ;i++)
		if (prime(i))
			return i;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	for (int i = 0; i < n; i++)
		a[i] = 1;

	int k = 1;
	for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				if (g[i][j])
					{
						k = next_prime(k);
						a[i] *= k;
						a[j] *= k;
					}
			if (a[i] == 1)
				{
					k = next_prime(k);
					a[i] = k;
				}
		}

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}

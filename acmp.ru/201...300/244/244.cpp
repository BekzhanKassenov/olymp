#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, k;

vector <int> a;

bool check()
{
	for (int i = k; i < n; i++)
		if (a[i] != a[i - k])
			return false;

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> k;

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (check())
		{
			cout << "OK\n0";
			return 0;
		}

	for (int i = k; i < n; i++)
		{
			if (a[i] != a[i - k])
				{
					a[i - k] = 1 - a[i - k];
					if (check())
						{
							cout << "OK\n" << i - k + 1;
							return 0;
						}

					a[i - k] = 1 - a[i - k];
					a[i] = 1 - a[i];

				if (check())
					{
						cout << "OK\n" << i + 1;
						return 0;
					}	
				cout << "FAIL";
				return 0;
				}
		}

	return 0;
}

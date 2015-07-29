#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int check(int a, int b)
{
	bool used[10] = {0};

	while (a)
		{
			used[a % 10] = true;
			a /= 10;
		}

	while (b)
		{
			if (used[b % 10])
				return false;

			b /= 10;
		}

	return true;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int a = 0;

	cout << a << endl;

	for (int i = 1; i < n; i++)
		{
			int x = a;

			while (!check(++x, a));

			a = x;

			cout << a << endl;

		}

	cout << a;
	
	return 0;
}

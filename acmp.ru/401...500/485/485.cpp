#include <iostream>
#include <cstdio>

using namespace std;

int n, k;

bool check(int a)
{
	for (int i = 0; i < n; i++)
		{
			if (a % (n - 1) != 0)
				return false;

			a = (a / (n - 1)) * n + k;
		}

	cout << a;

	return true;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> k;

	int i = 1;

	while (true)
		{
			if (check(i))
				{
					return 0;
				}
			i++;
		}

}

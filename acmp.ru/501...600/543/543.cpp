#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	
	cin >> n;

	int w, d, p;

	cin >> w >> d >> p;

	int sum = 0;

	for (int i = 1; i < n; i++)
		sum += w * i;

	if (sum == p)
		{
			cout << n;
			return 0;
		}

	for (int i = 1; i < n; i++)
		{
			int tmp = sum - i * d;

			if (tmp == p)
				{
					cout << i;
					break;
				}
		}

	return 0;	
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

long long n;

map <long long, int> m;

bool win(long long nmb)
{
	if (nmb >= n)
		{
			m[nmb] = 2;
			return false;
		}

	int ans = m[nmb];

	if (ans != 0)
		{
			if (ans == 1)
				return true;

			return false;
		}

	for (int i = 2; i <= 9; i++)
		{
			bool q = win(nmb * i);

			if (q == false)
				{
					m[nmb] = 1;
					return true;
				}
		}

	m[nmb] = 2;
	return false;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;

	if (win(1))
		cout << "Stan";
	else
		cout << "Ollie";

	cout << " wins.";
	return 0;
}

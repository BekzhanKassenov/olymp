#include <iostream>
#include <cstdio>

using namespace std;

bool lucky(int n)
{
	while (n)
		{
			if (((n % 10) != 4) && ((n % 10) != 7))
				return false;
			n /= 10;
		}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
				{
					if (lucky(i))
						{
							cout << "YES";
							return 0;
						}
					else
						if (lucky(n / i))
							{
								cout << "YES";
								return 0;
							}
				}
	   }
	cout << "NO";
	return 0;
}


#include <iostream>
#include <cstdio>

using namespace std;

int d[10];

int main()
{
	int n;
	cin >> n;
	if (n == 0)
		{
			cout << 10;
			return 0;
		}
	if (n == 1)
		{
			cout << 1;
			return 0;
		}
		
	for (int i = 9; i >= 2; i--)
		while (n % i == 0)
			{
				n /= i;
				d[i] ++;
			}
	if (n > 1)
		{
			cout << -1;
			return 0;
		}
	for (int i = 2; i <= 9; i++)
		for (; d[i]; d[i] --)
			cout << i;
	return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	if (n < k)
		{
			cout << -1;
			return 0;
		}

	for (int i = 0; i < n; i++)
		if (n - i <= k - 2)
			cout << char('a' + k - (n - i));
		else
			{
				cout << char('a' + i % 2);
			}	
}
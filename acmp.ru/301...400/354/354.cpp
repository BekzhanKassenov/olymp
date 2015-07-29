#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int k = sqrt (1.0 * n);
	int i = 2;
	while (i<=k)
		{
			if (n % i == 0)
				{
					cout << i;
					n /= i;
					if (n > 1)
						cout << '*';
				}
			else
				i++;
		}
	if (n > 1)
		cout << n;
	return 0;
}

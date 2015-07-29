#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;

	cin >> n;

	if (n == 1)
		cout << 14;

	if (n == 2)
		cout << 155;

	if (n >= 3)
		{
			cout << 1575;

			for (int i = n - 3; i > 0; i--)
				cout << 0;

		}
	return 0;	
}

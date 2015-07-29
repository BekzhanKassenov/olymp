#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a = 1;
	while (n)
		{
			if (a == n)
				{
					cout << a;
					return 0;
				}
			n -= a;
			a++;
		}
}

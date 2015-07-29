#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b, c, d;

	cin >> a >> b >> c >> d;

	if (a > c)
		{
			cout << a;
			return 0;
		}

	for (;;)
		{
			if (a + b >= c)	
				{
					cout << c;
					return 0;
				}

			else
				a += b;

			if (c - d <= a)
				{
					cout << a;
					return 0;
				}
			else
				c -= d;	
				
		}
}

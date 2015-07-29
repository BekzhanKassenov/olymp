#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int m1 = 0 ,m2 = 0;
	int a;
	for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a == m1 || a == m2)
				continue;
			if (a > m1)
				{
					m2 = m1;
					m1 = a;
				}
			else
				if (a > m2)
					m2 = a;
		}
	cout << m2;
	return 0;
}

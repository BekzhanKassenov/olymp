#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int f = 1;
	int f1 = 1;
	int f2 = 1;
	for (int i = 1; i < n; i++)
		{
			f2 = (f1 + f) % 10;
			f = f1;
			f1 = f2;
		}
	cout << f2;
	return 0;
}

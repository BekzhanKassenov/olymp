#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long f, f1 ,f2;
	f2 = 0;
	f1 = f = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		{
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
	cout << f;
	return 0;
}

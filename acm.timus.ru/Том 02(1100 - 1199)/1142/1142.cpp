#include <iostream>
#include <cstdio>

using namespace std;

int fact(int n)
{
	if (n == 1)
		return 1;

	else	
		return fact(n - 1) * n;
}

int main()
{
	int n;

	cin >> n;

	while (n != -1)
		{
			cout << fact(n) * (n - 1) + 1 << endl;
			cin >> n;
		}
	return 0;
}


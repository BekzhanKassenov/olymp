#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long a, b;

	cin >> a >> b;

	long long c;

	cin >> c;

	if (a < 0)
		{
			a += (-a / c) * c;
			a += c;
		}

	if (b < 0)
		{
			b += (-b / c) * c;
			b += c;
		}

	cout << ((a % c) + (b % c) + c) % c;

	return 0;
}

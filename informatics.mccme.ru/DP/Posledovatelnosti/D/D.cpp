#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int d[3000];
	d[0] = d[1] = 1;
	for (int i = 0; i <= n / 2 + 1; i++)
		{
			d[2 * i] = d[i] + d[i - 1];
			d[2 * i + 1] = d[i] - d[i - 1];
		}
	cout << d[n];
}

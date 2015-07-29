#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	k %= n;
	for (int i = n - k + 1; i <= n; i++)
		{
			cout << i << ' ';
		}
	for (int i = 1; i < n - k + 1; i++)
		cout << i << ' ';
	return 0;
}

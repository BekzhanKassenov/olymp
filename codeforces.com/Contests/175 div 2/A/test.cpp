#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int n, k;

	cin >> n >> k;

	for (int i = 1; i < n - k; i++)
		cout << i << ' ' ;

	for (int i = n; k >= 0; k--, i--)
		cout << i << ' ';

	return 0;	
}

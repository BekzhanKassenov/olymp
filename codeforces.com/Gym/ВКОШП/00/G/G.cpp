#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;

	cin >> n;

	for (int i = 0; i < n - 2; i ++)
		{
			cout << 1 << ' ';
		}
	
	cout << 2 << ' ' << n;
	return 0;
}


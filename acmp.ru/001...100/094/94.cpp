#include <iostream>
#include <cstdio>

using namespace std;

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, k;

	cin >> n >> m >> k;

	if (n >= m)
		{
			cout << 1;
			return 0;
		}

	if (k >= n)
		{
			cout << "NO";
			return 0;
		}

	cout << ((m - k - 1) / (n - k)) + 1;
	
}

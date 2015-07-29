#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n==1)
		{
			cout << 1;
			return 0;
		}
	if (n == 2)
		{
			cout << 3;
			return 0;
		}
	if (n == 3)
		{
			cout << 5;
			return 0;
		}
	int m = n / 4;
	int ans = 0;
	if (m == 1 || m == 2)
		{
			cout << 2 * m + 1;
			return 0;
		}
	else
		{
			while ((ans * ans) / 2 < m)
				ans++;
		}
	cout << 2*ans + 1;
}

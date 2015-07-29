#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(32000, 0);
	int l, r;
	for (int i = 0; i < n; i++)
		{
			cin >> l >> r;
			for (int j = l; j <= r; j++)
				a[j] ++;
		}
	int ans = 0;
	for (int i = 0; i < 32000; i++)
		if (a[i] == n)
			ans ++;
	cout << max(ans - 1, 0);
	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	int k;
	cin >> k;
	int mn = 2000000000;
	int ans = 0;
	for (int i = 0; i < n; i++)
		{
			if (mn > abs(a[i] - k))
				{
					mn = abs(a[i] - k);
					ans = i + 1;
				}
		}
	cout << ans;
	return 0;
}

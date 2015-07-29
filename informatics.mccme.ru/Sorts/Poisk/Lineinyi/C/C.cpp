#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()                  
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int x;
	cin >> x;
	int ans = 10000;
	for (int i = 0; i < n; i++)
		if (abs(a[i] - x) < abs(ans - x))
			ans = a[i];
	cout << ans;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long

int main()
{
	int n;

	cin >> n;

	vector <LL> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	if (a[n - 3] * a[n - 2] * a[n - 1] > a[0] * a[1] * a[n - 1])
		{
			cout << a[n - 3] << ' ' << a[n - 2] << ' ' << a[n - 1];
		}
	else
		cout << a[0] << ' ' << a[1] << ' ' << a[n - 1];

	return 0;	
}

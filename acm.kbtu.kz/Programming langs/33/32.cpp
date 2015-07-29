#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = i;
	int k;
	cin >> k;
	int l, r;
	for (int i = 0; i < k; i++)
		{
			cin >> l >> r;
			swap(a[l], a[r]);
		}
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mn = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < a[mn])
			mn = i;
	swap(a[0], a[mn]);

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
}

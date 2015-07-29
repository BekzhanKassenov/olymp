#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> a;

int n;

bool found (int x)
{
	int l = 0, r = n - 1;
	while (l < r)
		{
			int m = (l + r) / 2;
			if (a[m] == x || a[l] == x || a[r] == x)
				return true;
		   if (a[m] < x)
		   	l = m + 1;
		   else
		   	r = m;
		}
	return false;
}

int main()
{
	int m;
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int v;
	for (int i = 0; i < m; i++)
		{
			cin >> v;
			if (found(v))
				cout << "YES";
			else
				cout << "NO";
			cout << endl;
		}
	return 0;
}

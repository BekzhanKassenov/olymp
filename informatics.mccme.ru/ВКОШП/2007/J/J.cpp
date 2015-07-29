#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int> > b;

int abs(int a)
{
	return (a < 0) ? (-a) : a;
}

int bin_search(int l, int r, int val)
{
	if (abs (l - r) <= 1 || l > r)
		{	
			if (abs(b[l].first - val) < abs (b[r].first -  val))
				return b[l].second;
			else
				return b[r].second;
		}
	int m = (l + r) / 2;
	if (b[m].first == val)
		return b[m].second;
	if (val < b[m].first)
		return bin_search(l, m, val);
	else
		return bin_search(m, r, val);
}

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	b.resize(m);
	for (int i = 0; i < m; i++)
		{
			cin >> b[i].first;
			b[i].second = i;
		}
	sort(b.begin(),b.end());

	for (int i = 0; i < n; i++)
		cout << bin_search(0, m, a[i]) + 1 << ' ';
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair <int, int> a, pair <int, int> b)
{
	if (a.first > b.first)	
		return true;
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n;
	cin >> n;

	vector <pair <int, int> > a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i].second >> a[i].first;
	
	sort(a.begin(), a.end(), cmp);
	
	for (int i = 0; i < n; i++)
		cout << a[i].second << ' ' << a[i].first << endl;
	
	return 0;
}

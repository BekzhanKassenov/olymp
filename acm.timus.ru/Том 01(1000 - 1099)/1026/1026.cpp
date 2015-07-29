#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	string s;
	cin >> s;
	sort(a.begin(), a.end());

	int m;
	cin >> m;
	
	int x;

	for (int i = 0; i < m; i++)
		{
			cin >> x;
			cout << a[--x] << endl;
		}
	return 0;
}

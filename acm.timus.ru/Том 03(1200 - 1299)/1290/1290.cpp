#include <iostream>
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

	sort(a.rbegin(), a.rend());

	for (int i = 0; i < n; i++)	
		cout << a[i] << endl;


}
	

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
	int mx = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > a[mx])
			mx = i;
	cout << mx + 1;
	return 0; 
}


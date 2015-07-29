#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	
	cin >> n;

	vector <int> a(n);

	int pos = -1;

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 1)
				pos = i;
		}

	for (int i = pos; i < n; i++)
		cout << a[i] << ' ';

	for (int i = 0; i < pos; i++)
		cout << a[i] << ' ';
	return 0;
}


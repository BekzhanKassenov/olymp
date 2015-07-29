#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define F first
#define S second

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <pair <int, int> > a(n);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i].F;
			a[i].S = i + 1;
		}

	sort(a.begin(), a.end());

	int pos = 0;

	for (int i = 0; i < n - 1; i++)
		{
			if (a[i + 1].F - a[i].F < a[pos + 1].F - a[pos].F)
				pos = i;
		}

	cout << a[pos + 1].F - a[pos].F << endl << a[pos].S << ' ' << a[pos + 1].S;
	return 0;
}

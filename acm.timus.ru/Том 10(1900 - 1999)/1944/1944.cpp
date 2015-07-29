#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <PII> c(n);

	int maxx = -200, maxy = -200, minx = 200, miny = 200;

	for (int i = 0; i < n; i++)
		{
			cin >> c[i].F >> c[i].S;
			maxx = max(c[i].F, maxx);
			minx = min(c[i].F, minx);

			maxy = max(c[i].S, maxy);
			miny = min(c[i].S, miny);
		}

	vector <vector <char> > a(400, vector <char> (400, '.'));

	for (int i = 0; i < 400; i++)
		a[200][i] = '-';

	for (int i = 0; i < 400; i++)
		a[i][200] = '|';

	a[200][200] = '+';

	for (int i = 0; i < n; i++)
		a[200 + c[i].S][200 + c[i].F] = '*';

	for (int i = max(200, 200 + maxy); i >= min(200, 200 + miny); i--)
		{
			for (int j = min(200, 200 + minx); j <= max(200, 200 + maxx); j++)
				cout << a[i][j];
			cout << endl;
		}
	return 0;
}

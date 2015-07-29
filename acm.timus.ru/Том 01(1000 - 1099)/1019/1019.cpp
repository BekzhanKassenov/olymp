#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define F first
#define S second
#define MP make_pair

struct t
{
	pair <int, int> cr;
	int cv;
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	char c;

	vector <t> a (n + 1);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i].cr.F >> a[i].cr.S >> c;

			if (c == 'w')
				a[i].cv = 1;

			else
				a[i].cv = 0;	
		}

	a[n].cr.F = 0;
	a[n].cr.S = 1000000000;
	a[n].cv = 
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct tme
{
	int h, s, m;
};

bool operator < (tme a, tme b)
{
	if (a.h < b.h)
		return true;
	if (a.h > b.h)
		return false;
	if (a.m < b.m)
		return true;
	if (a.m > b.m)
		return false;
	if (a.s < b.s)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	vector <tme> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].h >> a[i].m >> a[i].s;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		cout << a[i].h << ' ' << a[i].m << ' ' << a[i].s << endl;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

vector <int> a;

vector <int> p;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n;

	cin >> m >> n;

	vector <PII> tmp(m);

	for (int i = 0; i < m; i++)
		cin >> tmp[i].F >> tmp[i].S;

	a.resize(n);
	p.resize(n);

	vector <PII> b(n);

	for (int i = 0; i < n; i++) {
		cin >> b[i].F;
		b[i].S = i;
	}

	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
		a[i] = b[i].F;

	vector <PII> flag(n);

	for (int i = 0; i < m; i++) {
		int l = tmp[i].F, r = tmp[i].S;

		if (l > r)
			swap(l, r);

		int pos1 = lower_bound(a.begin(), a.end(), l) - a.begin();

		int pos2 = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;

		//cout << l << ' ' << r << ' ' << pos1 << ' ' << pos2 << endl;

		if (pos1 <= pos2 && pos1 < n) {
			flag[pos1].F++;
			flag[pos2].S++;
		}
	}

	int cur = 0;

	for (int i = 0; i < n; i++) {
		cur += flag[i].F;

		b[i].F = b[i].S;
		b[i].S = cur;
		
		cur -= flag[i].S;
	}

	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
		cout << b[i].S << ' ';

	return 0;	
}
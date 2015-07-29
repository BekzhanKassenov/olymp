//This solution based on Segment Tree

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

vector <int> t;

void push(int v, int l, int r) {
 	if (l == r) {
 		p[l] += t[v];
 		t[v] = 0;
 	} else {
 		t[v << 1] += t[v];
 		t[(v << 1) + 1] += t[v];
 	}
}

void upd(int v, int l, int r, int z_l, int z_r) {
 	if (l > r || l > z_r || r < z_l)
 		return;

 	if (l >= z_l && r <= z_r)
 		t[v]++;
 	else {
 		int m = (l + r) >> 1;

 		push(v, l, r);

 		upd(v << 1, l, m, z_l, z_r);
 		upd((v << 1) + 1, m + 1, r, z_l, z_r);
	}	
}

void make(int v, int l, int r) {
	if (l > r)
		return;

	push(v, l, r);

	if (l != r) {
		int m = (l + r) >> 1;

		make(v << 1, l, m);
		make((v << 1) + 1, m + 1, r);
   	}
}

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
	t.resize(n * 4);

	vector <PII> b(n);

	for (int i = 0; i < n; i++) {
		cin >> b[i].F;
		b[i].S = i;
	}

	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
		a[i] = b[i].F;

	for (int i = 0; i < m; i++) {
		int l = tmp[i].F, r = tmp[i].S;

		if (l > r)
			swap(l, r);

		int pos1 = lower_bound(a.begin(), a.end(), l) - a.begin();

		int pos2 = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;

		//cout << l << ' ' << r << ' ' << pos1 << ' ' << pos2 << endl;

		if (pos1 <= pos2)
			upd(1, 0, n - 1, pos1, pos2);
	}

	make(1, 0, n - 1);

	for (int i = 0; i < n; i++) {
		b[i].F = b[i].S;
		b[i].S = p[i];
	}

	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
		cout << b[i].S << ' ';

	return 0;	
}
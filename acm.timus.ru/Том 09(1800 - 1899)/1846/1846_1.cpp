#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define F first
#define S second
#define MP make_pair

const int maxn = 100010;

int t[4 * maxn];
vector <pair <int, int> > a;
set <int> s;

int gcd(int a, int b) {
	if (!a || !b)
		return a + b;

	return gcd(b % a, a);
}

void upd(int v, int l, int r, int val, int cnt) {
	if (l > r || a[l].F > val || a[r].F < val) 
		return; 	

	if (l == r) {
		assert(a[l].F == val);

	 	a[l].S += cnt;

	 	if (a[l].S > 0)
	 		t[v] = val;
	 	else
	 		t[v] = 0;

	 	return;
	}

	int m = (l + r) >> 1;

	upd(v << 1, l, m, val, cnt);
	upd((v << 1) + 1, m + 1, r, val, cnt);

	t[v] = gcd(t[v << 1], t[(v << 1) + 1]);
}

int main() {
   	#ifndef ONLINE_JUDGE
   		freopen("in", "r", stdin);
   	#endif

   	int n;

   	cin >> n;

   	vector <pair <int, char> > b(n);

   	for (int i = 0; i < n; i++) {
   		cin >> b[i].S >> b[i].F;

   		s.insert(b[i].F);
   	}

   	a.reserve(s.size());

   	int sz = s.size();

   	for (set <int> :: iterator it = s.begin(); it != s.end(); it++) 
   		a.push_back(MP(*it, 0));

   	for (int i = 0; i < n; i++) {
   		if (b[i].S == '+') 
   			upd(1, 0, sz - 1, b[i].F, 1);
   		else
   			upd(1, 0, sz - 1, b[i].F, -1);
   				
   		printf("%d\n", t[1] ? t[1] : 1);
   	}

   	return 0;
}
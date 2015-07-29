/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

void get_repr(long long p, long long q, vector <long long>& res) {
 	res.clear();

 	while (p && q) {
 	 	res.push_back(p / q);
 	 	p %= q;
 	 	swap(p, q);
 	}
}

long long p, q;
int n;
vector <long long> a;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	scanf("%I64d%I64d", &p, &q);

	scanf("%d", &n);
	a.resize(n);

	for (int i = 0; i < n; i++) {
	 	scanf("%I64d", &a[i]);
	}
	
	if (a.back() == 1 && a.size() > 1u) {
		a.pop_back();
		a.back()++;
	}

	vector <long long> b;
	get_repr(p, q, b);

	if (a == b) {
	 	puts("YES");
	} else {
	 	puts("NO");
	}

    return 0;
}

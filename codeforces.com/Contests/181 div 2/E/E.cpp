/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define MOD (1000 * 1000 * 1000 + 7)

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
T sqr(T n) {
	return (n * n);
}
int n;

vector <ll> lp, pr, a;

ll st[(int)1e7 + 10];
ll mx = 0;

void build() {
	for (int i = 2; i <= mx; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);	
		}

		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * 1ll * pr[j] <= mx; ++j)
			lp[pr[j] * i] = pr[j];
	}
}

ll fact_pow(ll i, ll m) {
    ll res = 0;

    while (m) {
    	m /= i;
    	res += m;
    }

    return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);
	a.resize(n);

	ll sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		sum += a[i];
		mx = max(mx, a[i]);
	}

	lp.resize(mx + 1);

	build();

	a.push_back(0);

	sort(a.begin(), a.end());

	for (int i = 1; i <= n; i++) {
		for (int j = a[i - 1] + 1; j <= a[i]; j++) {
			int x = j;
				
			while (x > 1) {
				st[lp[x]] += (n - i + 1);
				x /= lp[x];
			}
		}	
	}

	ll l = 1, r = sum, ans = r;

	while (l <= r) {
	    ll m = (l + r) >> 1;

	    bool flag = true;

	    for (int i = 2; i <= (int)1e7; i++) {
	    	if (st[i] > 0 && fact_pow(i, m) < st[i])
	    		flag = false;
	    }

	    if (!flag)
	    	l = m + 1;
	    else {
	    	ans = min(ans, m);
	    	r = m - 1;
	    }

	    //cout << l << ' ' << r << endl;
	}

	cout << r + 1;

	return 0;
}

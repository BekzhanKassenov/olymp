#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 1000ll * 1000ll * 1000ll * 1000000ll * 1000ll;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 100010;

struct item {
 	ll t, l, v;
} a[maxn];

ll d, n, vo;

bool cmp(const item& a, const item& b) {
	return (a.l < b.l);
}

ll make(ll vi) {
 	//double tcur = a[0].t;
 	double tcur = (a[0].l + .0)/(vi + .0);

 	if (tcur >= a[0].t){
 		tcur = ceil(tcur);
 		vi -= a[0].v;
 	}

 	if (vi == 0 && n == 1 && a[n - 1].l == d)
 		return 0;

 	if (vi <= 0)
 		return -1;

 	for (int i = 1; i < n; i++) {
 		double tt = tcur + (a[i].l - a[i - 1].l + .0) / (vi + .0);

 		if (tt >= a[i].t) {
 			tcur = ceil(tt);
 			vi -= a[i].v;
 		} else 
 			tcur = tt;

 		if (vi < 0)
 			return -1;
 	}

 	if (vi == 0 && a[n - 1].l == d)
 		return vi;

 	if (vi < 0)
 		return -1;

 	return vi;
}

ll bin(ll l, ll r) {
	while (r - l > 100) {
		ll mid = (l + r) >> 1;
		
		ll res = make(mid);

		if (res == -1) {
			l = mid;
		} else 
			r = mid;

		//cout << l << ' ' << r << endl;	
	}

	for (ll i = l; i <= r; i++)
		if (make(i) != -1) 
			return i;

	return 0;
}

ll bin1(ll l, ll r) {
	while (r - l > 100) {
		ll mid = (l + r) >> 1;
		
		ll res = make(mid);

		if (res == vo)
			return mid;

		if (res < vo)
			l = mid;
		else
			r = mid;

		//cout << l << ' ' << r << endl;	
	}

	ll ans = INF, res = r;

	for (ll i = r; i >= l; i--) {
		ll k = make(i);
		if (abs(k - vo) <= ans) {
			ans = abs(k - vo);
			//cout << "ASD " << i << ' ' << make(i) << endl;
			res = i;
		}	
	}

	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> d >> n >> vo;

	if (n == 0) {
		cout << vo;
		return 0;
	}

	for (int i = 0; i < n; i++) 
		cin >> a[i].l >> a[i].t >> a[i].v;

	sort(a, a + n, cmp);

	cout << bin1(bin(1, INF), INF);

	return 0;
}
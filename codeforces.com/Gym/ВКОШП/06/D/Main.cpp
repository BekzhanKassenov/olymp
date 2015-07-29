/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "elect"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}
typedef struct {
long long v, p, ii;
} par;
bool comp(const par & c, const par & b){
	if (c.v > b.v)
		return 1;
		else if (c.v == b.v && c.p < b.p)
		return 1;
		return 0;
}
const int maxn = 100010;
par a[maxn];
long long d[maxn], wans[maxn];
int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int n;
	scanf("%d", &n);

	ll sum = 0;
	ll ans = INF;
	for (int i = 0; i < n; i++) {
		scanf("%I64d%I64d", &a[i].v, &a[i].p);
		a[i].ii = i;
	}
	sort(a, a+n, comp);
	d[0] = a[0].v;
	for (int i = 1; i < n; ++i) 
		d[i] = d[i-1] + a[i].v; 
	
    int index = -1000;
   	long long tp;

	for (int i = 0; i < n; ++i){
	
		if (a[i].p != -1)                              {
			if (ans > (d[i] - (i + 1)*a[i].v + 1)/2 + a[i].p)
			{
				ans =(d[i] - (i + 1)*a[i].v + 1)/2 + a[i].p;
				index = i; 
			}
			// cout << (d[i] - (i + 1)*a[i].v + 1)/2 << endl;
			}
	}
	
	cout << ans << endl;
	for (int i = 0; i < index; ++i){
		if (a[i].v >= tp)
			a[i].v = tp-1;
		wans[a[i].ii] = a[i].v; 	
	}
	for (int i = 0; i < n; ++i)
		cout << wans[i] << " ";

	return 0;
}

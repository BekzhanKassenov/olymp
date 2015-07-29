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
#define File "fence"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, k, a[maxn];

bool check(int x) {
	long long last = a[0];
	for (int i = 1; i < n; i++){
		if ((long long)a[i] - last < (long long)x)
			last += (long long)x;
		else
			last = (long long)a[i];
	}
    if (last > (long long)k)
    	return 0;
    return 1;	
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int l = 0, r = a[0];

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		
		if (check(mid))
			l = mid;
		else
			r = mid - 1;	
	}
	if (check(r))	
		cout << r;
	else
		cout << l;

	return 0;
}


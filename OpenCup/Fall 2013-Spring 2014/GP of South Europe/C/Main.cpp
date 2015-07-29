/****************************************
**         Solution by NU_02           **
****************************************/

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
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 10010;
int a[maxn][maxn];

int main() {
	FILE* f = fopen("c.in", "rb");
	int n, m;
	fread(&n, sizeof(n), 1, f);
	fread(&m, sizeof(m), 1, f);
	
	for (int i = 0; i < n; i++)
		fread(&a[i][0], 4, m, f);

	int x, y;

	while (fread(&x, sizeof(x), 1, f)) {
		fread(&y, sizeof(y), 1, f);
		
		int ans = 0;
		
		for (int i = 0; i < n; i++)
			ans += upper_bound(a[i], a[i] + m, y) - lower_bound(a[i], a[i] + m, x);
		
		cout << ans << endl;
	}

	return 0;
}

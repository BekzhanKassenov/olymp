/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int h, m;

	scanf("%d:%d", &h, &m);

	int dh, dm;

	scanf("%d:%d", &dh, &dm);

	m  +=  h * 60;
	dm += dh * 60;

	dm %= 60 * 24;

	m = (m - dm + 60 * 24) % (60 * 24);

	h = m / 60;
	m %= 60;

	printf("%02d:%02d", h, m);

	return 0;
}


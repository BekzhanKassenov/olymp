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

bool cmp(const PII& a, const PII& b) {
	return (abs(a.F) + abs(a.S) < abs(b.F) + abs(b.S));
}

stringstream ss;

int ans;

void move_x(int a, int b) {
	int dir = b - a;

	if (dir == 0)
		return;

	ans++;
	ss << "1 " << abs(dir) << ' ' << ((dir > 0) ? 'R' : 'L') << endl;	
}

void move_y(int a, int b) {
	int dir = b - a;

	if (dir == 0)
		return;
 	
 	ans++;
 	ss << "1 " << abs(dir) << ' ' << ((dir > 0) ? 'U' : 'D') << endl;
}

void move(const PII& a, const PII& b) {
	move_x(a.F, b.F);
	move_y(a.S, b.S);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	vector <PII> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	sort(all(a), cmp);

	PII st(0, 0);

	for (int i = 0; i < n; i++) {
		move(st, a[i]);
		ss << 2 << endl;
		move(a[i], st);
		ss << 3 << endl;
		ans += 2;
	}

	cout << ans << endl << ss.str();

	return 0;
}

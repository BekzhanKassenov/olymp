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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
char s[MAXN];
vector <int> v;

int get_opt(int l, int r) {
	int dist = (v[r] - v[l]) / 2;
	int _left = l, _right = r;

	while (_right - _left > 10) {
		int mid = (_left + _right) / 2;

		if (v[mid] - v[l] > dist) {
			_right = mid;
		} else {
			_left = mid;
		}
	}

	int ans = INF;
	for (int i = _left; i <= _right; i++) {
		ans = min(ans, max(v[i] - v[l], v[r] - v[i]));
	}

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &k);
    gets(s);

    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') {
    		v.push_back(i);
    	}
    }

    int ans = INF;
    for (size_t i = 0; i + k + 1 <= v.size(); i++) {
    	int r = i + k;
    	ans = min(ans, get_opt(i, r));
    }

    printf("%d\n", ans);

    return 0;
}

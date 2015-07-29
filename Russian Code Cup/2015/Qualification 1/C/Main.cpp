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

enum {
	MAT,
	PHI
};

bool mat[15], phi[15];
int type[40], country[40];
int ans = 0;
int n;

void go(int pos) {
	if (pos == 2 * n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!mat[i]) {
			bool flag = false;
			if (pos == 0) {
				flag = true;
			}

			if (pos >= 1 && country[pos - 1] != i) {
				flag = true;
			}

			if (pos >= 2 && (type[pos - 1] != PHI || type[pos - 2] != MAT)) {
				flag = true;
			}

			flag = true;
		}

if (!mat[i]) {
			bool flag = false;
			if (pos == 0) {
				flag = true;
			}

			if (pos >= 1 && country[pos - 1] != i) {
				flag = true;
			}

			if (pos >= 2 && (type[pos - 1] != PHI || type[pos - 2] != MAT)) {
				flag = true;
			}

			flag = true;
		}
	}
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
	int n;

    return 0;
}

/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "field"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN][MAXN];
bool used[MAXN][MAXN];

bool ok(int i, int j, int color) {
	if (i < 0 || j < 0 || i >= MAXN || j >= MAXN) return false;
	if (used[i][j]) return false;
	used[i][j] = true;
	a[i][j] = color;
	return true;
}

queue<pair<int, int> > q;


void step(pair<int, int> x) {
	if (ok(x.F + 2, x.S + 1, a[x.F][x.S]) ) {
		q.push(MP(x.F + 2, x.S + 1));
	}
	if (ok(x.F + 1, x.S - 2, a[x.F][x.S]) ) {
		q.push(MP(x.F + 1, x.S - 2));
	}
	if (ok(x.F - 1, x.S + 2, a[x.F][x.S]) ) {
		q.push(MP(x.F - 1, x.S + 2));
	}
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);

    a[0][0] = 1;
    a[0][1] = 5;
    a[0][2] = 3;
    a[0][3] = 2;
    a[0][4] = 4;
    q.push(MP(0, 0));
    q.push(MP(0, 1));
    q.push(MP(0, 2));
    q.push(MP(0, 3));
    q.push(MP(0, 4));

    while (!q.empty()) {
    	pair<int, int> tp;
    	tp = q.front();
    	q.pop();
    	step(tp);
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++)
    		printf("%d ", a[i][j]);

    	puts("");
    }

    return 0;
}

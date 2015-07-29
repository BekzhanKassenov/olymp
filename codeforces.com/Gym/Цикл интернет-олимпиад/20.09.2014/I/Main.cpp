/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "tic-tac-toe"

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

int dx[] = {1, 1, 0, 1};
int dy[] = {1, 0, 1, -1};

int n, m;
char s[1010][1010];

bool ok(int x, int y) {
 	return 0 <= x && x < n && 0 <= y && y < m;
}

bool check(int x, int y, int i) {
 	int tx = x, ty = y;

 	if (s[x][y] == '.')
 		return false;

 	for (int z = 0; z < 5; z++) {
 		if (!ok(tx, ty) || s[tx][ty] != s[x][y])
 			return false;

 		tx += dx[i];
 		ty += dy[i];
    }

    return true;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
     	gets(s[i]);
    }

    for (int i = 0; i < n; i++) {
     	for (int j = 0; j < m; j++) {
     	 	for (int k = 0; k < 4; k++) {
     	 	 	if (check(i, j, k)) {
     	 	 	 	puts("Yes");
     	 	 	 	return 0;
     	 	 	}
     	 	}
     	}
    }

    puts("No");
    return 0;
}

/****************************************
**          Solution by NU #2          **
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

int T;
int n;
int ans;

char grid[4][4] = {"123",
                   "456",
                   "789",
                   " 0 "};

int dx[] = {1, 0};
int dy[] = {0, 1};

bool ok(int x, int y) {
 	if (x == 3 && y == 1)
 		return true;

 	return 0 <= x && x < 3 && 0 <= y && y < 3;
}

void dfs(int x, int y, int num) {
	if (abs(num) > 500)
		return;

 	if (num && abs(n - num) < abs(n - ans)) {
 		ans = num;
 	}

 	for (int i = 0; i < 2; i++) {
 	 	int tx = x + dx[i];
 	 	int ty = y + dy[i];

 	 	if (ok(tx, ty)) {
 	 	 	dfs(tx, ty, num * 10 + grid[tx][ty] - '0');
 	 		dfs(tx, ty, num);
 	 	}
 	}

 	dfs(x, y, num * 10 + grid[x][y] - '0');
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
     	scanf("%d", &n);
     	ans = 0;

     	for (int i = 0; i < 3; i++) {
     	 	for (int j = 0; j < 3; j++) {
     	 	 	dfs(i, j, grid[i][j] - '0');
     	 	}
     	}

     	printf("%d\n", ans);
    }
    
    return 0;
}

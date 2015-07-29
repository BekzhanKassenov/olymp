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
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd
#define File "cafe"

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

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool used[100][100];
int a[100][100];
int n, m, c;

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			for (int k = 0; k < n; k++) 
				for (int l = 0; l < m; l++) {
					if (k != i || l != j) {
						int cur = a[i][j] + a[k][l];
						used[i][j] = true;
						used[k][l] = true;

						for (int z = 0; z < 4; z++) {
							int tx = i + dx[z];
							int ty = j + dy[z];
							if (ok(tx, ty) && !used[tx][ty]) {
								cur += a[tx][ty];
								used[tx][ty] = true;
							}

							tx = k + dx[z];
							ty = l + dy[z];

							if (ok(tx, ty) && !used[tx][ty]) {
								cur += a[tx][ty];
								used[tx][ty] = true;
							}
						}

						for (int z = 0; z < 4; z++) {
							int tx = i + dx[z];
							int ty = j + dy[z];
							if (ok(tx, ty)) 
								used[tx][ty] = false;

							tx = k + dx[z];
							ty = l + dy[z];

							if (ok(tx, ty)) 
								used[tx][ty] = false;
						}

						used[i][j] = false;
						used[k][l] = false;
						
						if (cur >= c)
							ans++;
					}
				}

	cout << ans / 2 << endl;
	return 0;
}

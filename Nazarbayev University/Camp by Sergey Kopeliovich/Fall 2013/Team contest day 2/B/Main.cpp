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
#define File "knight"

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

char s[10][10];

int dx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1,  1,  2};

bool ok(int x, int y) {
	return (x >= 0 && x < 10 && y >= 0 && y < 10);
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	for (int i = 0; i < 10; i++)
		scanf("%s", s[i]);

	int ans = 0;

   	for (int i = 0; i < 10; i++) {
   		for (int j = 0; j < 10; j++) {
   			if (s[i][j] == '.') {
   				int cur = 0;
   				for (int k = 0; k < 8; k++) {
   					int tx = i + dx[k];
   					int ty = j + dy[k];
   					if (ok(tx, ty))
   						cur += (s[tx][ty] == 'h');
   				}

   				ans = max(ans, cur);
   		   	}
   		}
   	}


   	cout << ans;
	return 0;
}

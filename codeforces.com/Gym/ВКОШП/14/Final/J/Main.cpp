/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "travel"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int MAXN = 510;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};
const int let[] = {'S', 'E', 'W', 'N'};

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, m, k;
char a[MAXN][MAXN];
int dist[MAXN][MAXN];
int si, sj;

bool ok(int i, int j) {
 	return 0 <= i && i < n && 0 <= j && j < m;
}

char reverse(char c) {
 	if (c == 'S')
 		return 'N';

 	if (c == 'N')
 		return 'S';

 	if (c == 'W')
 		return 'E';

	return 'W';	
}

void bfs(int& si, int& sj) {
 	vector <int> I, J;
 	I.push_back(si);
 	J.push_back(sj);
 	memset(dist, 255, sizeof dist);
 	dist[si][sj] = 0;

 	for (size_t q = 0; q < I.size(); q++) {
 	 	int curi = I[q];
 	 	int curj = J[q];

 	 	for (int z = 0; z < 4; z++) {
 	 	 	int ti = curi + di[z];
 	 	 	int tj = curj + dj[z];

 	 	 	if (ok(ti, tj)) {
 	 	 	 	if (dist[ti][tj] == -1) {
 	 	 	 	 	dist[ti][tj] = dist[curi][curj] + 1;
 	 	 	 	 	I.push_back(ti);
 	 	 	 	 	J.push_back(tj);
 	 	 	 	}

 	 	 	 	if (a[ti][tj] == 'T') {
 	 	 	 	 	si = curi;
 	 	 	 	 	sj = curj;
 	 	 	 	 	break;
 	 	 	 	}
 	 	 	}
 	 	}
 	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d %d %d\n", &m, &n, &k);

	for (int i = 0; i < n; i++) {
	 	gets(a[i]);

	 	for (int j = 0; j < m; j++) {
	 	 	if (a[i][j] == 'V') {
	 	 	 	si = i;
	 	 	 	sj = j;
	 	 	 	a[i][j] = 'A';
	 	 	}
	 	}
	}

	bfs(si, sj);

	return 0;
}

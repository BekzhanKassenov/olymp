/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define pos first
#define table second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, vector <vector <char> > > str;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, x, y;

bool operator < (const str& a, const str& b) {
	if (a.pos != b.pos)
		return (a.pos < b.pos);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a.table[i][j] != b.table[i][j])
				return (a.table[i][j] < b.table[i][j]);

	return false;
}

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	while ((cin >> n >> x >> y) && n && x && y) {
		vector <vector <char> > a(n, vector <char> (n));
		x--, y--;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		queue <str> q;
		q.push(MP(x * n + y, a));
		map <str, int> m;
		m[str(x * n + y, a)] = 0;

		int ans = INF;

		while (!q.empty()) {
			int curx = q.front().pos / n;
			int cury = q.front().pos % n;
			int dist = m[q.front()];
			vector <vector <char> > tt = q.front().table;
		   	q.pop();
		   	if (tt[curx][cury] == 'E') {
		   		ans = min(ans, dist);
		   		continue;
		   	}

		   	for (int i = 0; i < 4; i++) {
		   		int tx = curx + dx[i];
		   		int ty = cury + dy[i];

		   		str cur(tx * n + ty, tt);

		   		if (ok(tx, ty) && tt[tx][ty] != '.' && (!m.count(cur) || m[cur] > dist + 1)) {
		   		 	m[cur] = dist + 1;
		   		 	q.push(cur);
		   		}
		   	}


		   	for (int i = 0; i < 4 && tt[curx][cury] > '1' && tt[curx][cury] <= '9'; i++) {
		   		int tx = curx + dx[i];
		   		int ty = cury + dy[i];

		   		bool flag = true;
		   		vector <vector <char> > ttable(tt);

		   		for (int j = 0; j < tt[curx][cury] - '0' && flag; j++, tx += dx[i], ty += dy[i])
		   			if (!ok(tx, ty) || tt[tx][ty] != '.')
		   				flag = false;
		   		
		   		if (flag) {
		   			tx = curx + dx[i];
		   			ty = cury + dy[i];

		   			for (int j = 0; j < tt[curx][cury] - '0'; j++, tx += dx[i], ty += dy[i])
		   				ttable[tx][ty] = '1';

		   			ttable[curx][cury] = '.';
		   			tx = curx + dx[i];
		   			ty = cury + dy[i];

		   			str cur(tx * n + ty, ttable);
		   			if (!m.count(cur) || m[cur] > dist + 1) {
		   				m[cur] = dist + 1;
		   				q.push(cur);
		   			}
		   		}
		   	}
		   	
		}
		cout << ans << endl;
	}
	                        
	return 0;
}

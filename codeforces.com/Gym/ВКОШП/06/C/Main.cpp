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
#define File "digits"

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

char a[5000][5000];

int n, m;

bool ok(int x, int y) {
	return (x >= 0 && x < 5000 && y < m && y >= 0);
}

struct que {
 	int a[100000];
 	int head, tail;
 	que () : head(0), tail(0) {}

 	void push(int a) {
 		q[tail++] = a;
 	}

 	int front() {
 	 	return a[head];
 	}

 	void pop() {
 		head++;
 	}

 	void clear() {
 		head = tail = 0;
 	}

 	bool empty() {
 		return (head <= tail);
 	}
};                          

que q;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void bfs(int x, int y, int d) { 
	q.clear();
	q.push(x * n + y);

	while (!q.empty()) {
		int cx = q.front() / n;
		int cy = q.front() % n;
		a[cx][cy] = '*';
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int tx = cx + dx[i];
			int ty = cy + dy[i];

			if (ok(tx, ty) && abs(tx - x) + abs(ty - y) <= d && a[tx][ty] == '*')
				q.push(tx, ty);
		}
	}
}

void make(int x, int y, int _x, int _y) {
	if (x == _x) {
		for (int i = min(y, _y); i <= max(y, _y); i++)
			if (ok(x, i))
				a[x][i] = '*'; 
		return;
	}

	if (y == _y) {
		for (int i = min(x, _x); i <= max(x, _x); i++)
			if (ok(i, y))
				a[i][y] = '*';
		return;
	}

	int dx = (_x - x) / abs(x - _x);
	int dy = (_y - y) / abs(y - _y);

	while (x != _x) {
		if (ok(x, y))
			a[x][y] = '*';

		x += dx;
		y += dy;
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int k, d;
	cin >> k >> d; 
	int w, h;
	cin >> w >> h;

	m = (w - 1) * (k - 1) + w;
	n = (h - 1) * (k - 1) + h;

	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int x, y, _x, _y;

		cin >> x >> y >> _x >> _y;

	}

	return 0;
}

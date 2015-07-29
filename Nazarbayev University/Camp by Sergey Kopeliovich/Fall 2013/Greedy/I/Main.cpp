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
#define File "black"

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

char a[100][100];
bool used[100][100];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

int n, m;

bool ok(int x, int y) {
  	return (x >= 0 && x < n && y >= 0 && y < m);
}

int paint(int x, int y, bool flag, char board[100][100]) {
	queue <int> q;
	q.push(x * 100 + y);
	used[x][y] = true;
	int res = 0;
	if (flag) {
		board[x][y] = 'b';
		res++;
	} else
		board[x][y] = 'w';	

	while (!q.empty()) {
		int cur_x = q.front() / 100;
		int cur_y = q.front() % 100;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = cur_x + dx[i];
			int ty = cur_y + dy[i];
			if (ok(tx, ty) && board[tx][ty] == '#') {
				if (board[cur_x][cur_y] == 'b')
					board[tx][ty] = 'w';
				else {
					board[tx][ty] = 'b';
					res++;
				}

				q.push(tx * 100 + ty);	
			}
		}
	}
	return res;
}

void clear(char q[100][100]) {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			q[i][j] = a[i][j];
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	cin >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

   	char temp[100][100];

   	for (int i = 0; i < n; i++) {
   		for (int j = 0; j < m; j++) {
   			if (a[i][j] == '#') {
   				clear(temp);
   				int t1 = paint(i, j, true, temp);
   				clear(temp);
   				int t2 = paint(i, j, false, temp);

   				if (t1 >= t2)
   					paint(i, j, true, a);
   				else
   					paint(i, j, false, a);	
   			}
   		}
   	}

   	for (int i = 0; i < n; i++) {
   		for (int j = 0; j < m; j++)
   			cout << a[i][j];
   		cout << endl;	
   	}

	return 0;
}

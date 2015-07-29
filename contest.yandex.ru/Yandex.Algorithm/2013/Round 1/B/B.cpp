/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, m;

bool move(int& a, int& b) {
	if (a & 1) {
		b--;
		if (b == -1) {
			b = 0;
			a++;
			if (a == n)
				return false;
		}
	} else {
		b++;
		if (b == m) {
			b = m - 1;
			a++;
			if (a == n)
				return false;
		}
	}
	return true;
}

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}

void make(int i, int j, vector <bool>& used, const vector <vector <char> >& r) {
	for (int k = 0; k < 4; k++) {
		int tx = i + dx[k];
		int ty = j + dy[k];
		if (ok(tx, ty) && r[tx][ty] != '0')
			used[r[tx][ty] - 'A'] = true;
	}
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	cin >> n >> m;

	bool flag = false;

	if (m > n) {
		flag = true;
		swap(n, m);
	}

	vector <vector <char> > p(n, vector <char> (m, '0'));

	int i = 0, j = 0;

	int cnt = 0, c = 0;

	char ans = 'A';

	for (;;) {
		cnt++;

		if (n * m - c < cnt) {
			cnt--;

			do {
				p[i][j] = ans;
			} while (move(i, j));

			break;
		}

		int tx = i, ty = j;

		vector <bool> used(26, false);

		for (int k = 0; k < cnt; k++) {
			make(tx, ty, used, p);
			move(tx, ty);
		}

		for (int k = 0; k < 26; k++)
			if (!used[k]) {
				ans = k + 'A';
				break;
			}

		for (int k = 0; k < cnt; k++) {
			p[i][j] = ans;
			c++;
			move(i, j);
		}
		if (i == n)
			break;
	}

	cout << cnt << endl;

	if (flag) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cout << p[j][i];
			cout << endl;	
		}
	} else
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
				cout << p[i][j];
			cout << endl;
		}

	return 0;
}

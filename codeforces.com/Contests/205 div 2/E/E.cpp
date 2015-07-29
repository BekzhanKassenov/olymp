/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

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

const int maxn = 1e6 + 10;

struct vec {
  	int a[maxn];
  	int sz;

  	vec() : sz() {}

  	void push_back(int val) {
  		a[sz++] = val;
  	}

  	size_t size() {
  		return sz;
  	}

  	void clear() {
  		sz = 0;
  	}

  	int operator [] (int n) {
  		return a[n];
  	}
};

int next[maxn][2], len[maxn];
bool start[maxn];
bool used[maxn];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	string s;

	getline(cin, s);

	int n = s.size();
	memset(next, -1, sizeof next);
	memset(start, 1, sizeof start);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			next[i][len[i]++] = (i + 1) % n;
			start[(i + 1) % n] = false;
		} else {
			next[(i + 1) % n][len[(i + 1) % n]++] = i;
			start[i] = false;
		}
	}

	vec cur;

	for (int i = 0; i < n; i++) {
		if (start[i]) {
			for (int j = 0; j < len[i]; j++) {
				cur.clear();
				cur.push_back(i);
				for (int tmp = next[i][j]; tmp != -1; tmp = next[tmp][0])
					cur.push_back(tmp);

				if ((int)cur.size() > 2) {
					ans++;

					for (int k = 0; k < (int)cur.size(); k++) 
						used[cur[k]] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			used[(i + 1) % n] = true;
			used[(i - 1 + n) % n] = true;
			ans++;
		}
	}

	cout << ans;	

	return 0;
}

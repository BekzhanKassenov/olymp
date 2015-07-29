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

int i, j, x, y, top;
char st[100000];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;
	getline(cin, s);

	int n = s.size();

	for (int i = 0; i < n; i++) {
		st[++top] = s[i];

		while (top >= 4 && st[top] == st[top - 1] && st[top - 2] == st[top - 3])
			top --;

		
		while (top >= 3 && st[top] == st[top - 1] && st[top] == st[top - 2])
			top --;

	}

	for (int i = 1; i <= top; i++)
		cout << st[i];
	return 0;
}

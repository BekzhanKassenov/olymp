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
#define File "minimize"

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

const int maxn = 100010;

char s[maxn];
bool used[maxn], prev[maxn], next[maxn];
int len = 0;

void make(int n) {
	if (n == 0) {
		s[len++] = '0';
		return;
	}

	int pos = len;

	while (n) {
		s[pos++] = ((n % 10) + '0');
		n /= 10;
	}

	reverse(s + len, s + pos);
	len = pos;
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int m, n;

	cin >> m >> n;

	for (int i = 1; i <= n; i++)
		make(i);

	int l = -1;

	vector <int> pos;

	for (int i = 0; i < len; i++)
		if (s[i] == '0')
			pos.push_back(i);

	int ptr = 0;

	while (m && ptr < (int)pos.size()) {
		if (pos[ptr] - l + 1 <= m) {
			m -= pos[ptr] - l + 1;
			for (int i = l + 1; i < pos[ptr]; i++) 
				used[i] = true;
			l = pos[ptr];
		} else 	
			break;
	}

	for (int i = pos[ptr] + 1; i < len; i++) {
		prev[i] = i - 1;
		next[i] = i + 1;
	}

	bool cont = true;

	while (cont && m) {
		int st = pos[ptr];
		for (int i = pos[ptr]; i < len; i++) 
			if (!used[i]) {
				st = i; 
				break;
			}

		bool changed = false;

		while (next[st] != len && m) {
			if (s[st] > s[next[st]]) {
				used[st] = true;
				m--;
				changed = true;
				prev[next[st]] = prev[st];
				next[prev[st]] = next[st];
			}
			st = next[st];
		}
		cont &= changed;
	}

	if (m) {
		for (int i = 0; i < len; i++)
			if (!used[i]) {
				used[i] = true;
				m--;
			}	
	}


	for (int i = 1; i < len; i++)
		if (!used[i])
			cout << s[i];

	return 0;
}

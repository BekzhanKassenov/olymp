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

template <size_t N>
struct bit_set {
 	ull a[(N >> 6) + 1];
 	int size;

 	bit_set() {
 	 	memset(a, 0, sizeof a);
 	 	size = 0;
 	}

 	void set(int pos) {
 		a[pos >> 6] |= (1ull << (pos & 63));
 		size++;
 	}

 	void erase(int pos) {
 		a[pos >> 6] ^= (1ull << (pos & 63));
 		size--;
 	}

 	bool operator == (const bit_set<N> b) const {
 		if (size != b.size)
 			return false;

 		for (int i = 0; i < (N >> 6) + 1; i++)
 			if (a[i] ^ b.a[i])
 				return false;

 		return true;
 	}
};

map <int, int> num;
const int maxn = 200100;
int a[maxn], b[maxn], last;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n, m, p;

	cin >> n >> m >> p;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!num.count(a[i]))
			num[a[i]] = ++last;

		a[i] = num[a[i]];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (!num.count(b[i]))
			num[b[i]] = ++last;

		b[i] = num[b[i]];
	}

	bit_set <last> fa[p];
	bit_set <last> fb;

	for (int i = 0; i < m; i++) {
	 	fb.set(b[i]);
	}

	int pos = 0;
	
	stringstream ss;

	for (int i = 0; i < n; i++) {
		if (pos == p)
			pos = 0;

		a[pos].set(a[i]);

		if (a[pos].size > fb.size())

		if (!(a[pos].size ^ fb.size)) {
			if (a[pos] == fb) {
			 	ss << i - (m - 1) * p + 1 << endl;
			}
		}
	}
	
	return 0;
}

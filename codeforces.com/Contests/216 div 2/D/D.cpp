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

const int maxn = 3010;
int p[maxn], cnt[maxn];
bool used[maxn][maxn]

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;

	double x;

	for (int i = 0; i < n; i++) {
	 	cin >> x;
	 	if (x == .0)
	 		p[i] = 0;
	 	else if (x == 1.0)
	 		p[i] = 2;
	 	else
	 		p[i] = 1;	
	}

	for (int i = n - 1; i >= 0; i--) {
		cnt[i] += (cnt[i + 1] + p[i] == '1');
	}

	queue <pair <PII, int> > q;
	q.push(MP(MP(0, 1), 0));
	used[0][1] = 1;

	while (!q.empty()) {
		int dist = q.front().S;
		if (dist > k)
			continue;

		int a = q.front().F.F;
		int b = q.front().F.S;

		q.pop();


	}

	return 0;
}

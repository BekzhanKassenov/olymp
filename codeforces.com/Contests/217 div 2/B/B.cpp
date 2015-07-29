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

bool used[110][110];
int len[110];

bool check(int i, int j) {
	if (len[i] < len[j])
		return true;

	int cnt = 0;	
		 
	for (int k = 0; k < 110; k++)
		if (used[i][k] && used[j][k])
			cnt++;

	return (cnt < len[j]);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	cin >> n;

	int x;

	for (int i = 0; i < n; i++) {
		cin >> len[i];

		for (int j = 0; j < len[i]; j++) {
			cin >> x;
			used[i][x] = true;
		}
	}

	for (int i = 0; i < n; i++) {
	 	bool ans = true;

	 	for (int j = 0; j < n; j++) {
	 		if (i != j) {
	 			ans &= check(i, j);
	 		}	
	 	}
	 	cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}

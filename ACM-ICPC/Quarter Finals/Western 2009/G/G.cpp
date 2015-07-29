/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
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
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 100010;
int divis[maxn][130];
int len[maxn];

void make(int n) {
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divis[n][len[n]++] = i;

			if (i * i != 0)
				divis[n][len[n]++] = n / i;
		}
	}

	sort(divis[n], divis[n] + len[n] + 1);
}

bool used[100010];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		double start = clock();
	#endif

	int n;

	cin >> n;

	for (int i = 2; i <= n; i++) 
		make(i);

	divis[1][len[1]++] = 1;

	#ifndef ONLINE_JUDGE 
	  	cout << endl << (clock() - start) / CLOCKS_PER_SEC << endl;
	#endif

	int ans = 0;

	for (int a = 1; a < n; a++) {
		for (int x = 1; a * x < n; x++) {
			int by = n - a * x;
			
			for (int i = len[by]; divis[by][i] > a && i >= 0; i--) {
				if (!used[divis[by][i]]) {
					ans++;
					used[divis[by][i]] = true;
				}
			}
		}

		for (int x = 1; a * x < n; x++) {
			int by = n - a * x;
			
			for (int i = len[by]; divis[by][i] > a && i >= 0; i--) {
				used[divis[by][i]] = false;
			}
		}
	}


	cout << ans;

	#ifndef ONLINE_JUDGE 
	  	cout << endl << (clock() - start) / CLOCKS_PER_SEC << endl;
	#endif

	return 0;
}

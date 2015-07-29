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

int prec[7][7] = {{0, 0, 0, 0, 0, 0, 0}, 
			   {0, 50, 60, 60, 60, 60, 60}, 
			   {0, 30, 100, 120, 120, 120, 120}, 
			   {0, 10, 80, 150, 180, 180, 180}, 
			   {0, -10, 60, 130, 200, 240, 240},
			   {0, -30, 40, 110, 180, 250, 300},
			   {0, -50, 20, 90, 160, 230, 300}
			  };
double a[100][7];
bool cont = 1;
int p[7];
int ans[100];
int dp[100][7][1000];
PII pr[100][7][1000];
int n, k;

vector <int> get(int st) {
	vector <int> res;

	int t = k;

	for (int i = n - 1; i >= 0; i--) {
		int prevj = pr[i][st][t].F, prevk = pr[i][st][t].S;

		res.push_back(st);
		st = prevj;
		t = prevk;
	}
	return res;
}

bool operator < (const vector<int>& a, const vector<int>& b) {
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] < b[i])
			return true;

		if (a[i] > b[i])
			return false;
	}
	return false;
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; ++j)	
		cin >> p[j];
		for (int j = 0; j < 7; ++j){
			int ans = 0;
			for (int t = 0; t < 7; ++t){
				ans += p[t]*prec[j][t];
			}
			double tp = (double)ans/100.0;
			a[i][j] = tp;
		}	
	}

	for (int j = 0; j < 7; j++) {
		dp[0][j][j] = a[0][j];
		for (int l = 0; l <= k; l++)
			pr[0][j][k] = MP(0, 0);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			for (int l = j; l <= k; l++) {
				pr[i][j][l] = MP(0, 0);
				for (int z = 0; z < 7; z++) {
					int nl = l - j;
					if (nl >= z) {
						int prev = dp[i - 1][z][nl] + a[i][j];
						if (prev >= dp[i][j][l]) {
							dp[i][j][l] = prev;
							pr[i][j][l] = MP(z, nl);
						}
					}	
				}
			}
		}
	}

	int st = 0;
	vector <int> ans = get(0);
	reverse(all(ans));

	for (int i = 1; i < min(7, k); i++) {
		if (dp[n][i][k] > dp[n][st][k]) {
			st = i;
			ans = get(st);
		} else {
			if (dp[n][i][k] == dp[n][st][k]) {
				vector <int> tmp = get(i);
				reverse(all(tmp));
				if (tmp < ans)
					ans = tmp;
			}
		}
	}

	reverse(all(ans));

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	return 0;
}

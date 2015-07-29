/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "nice"

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
long long m, p;
string str;
bool check(int i, int j){
	for (int k = 1; k < m; ++k){
		if ((i&(1<<k)) == (j&(1<<k)) && (i&(1<<(k-1))) == (j&(1<<(k-1))) && ((i&(1<<k))>>1) == (j&(1<<(k-1))))
			return 0;
	}	
	return 1;
}
long long tem[33][33];
    long long dp[20][33];
int main() {
	freopen(File".in", "r", stdin);
	freopen("zarlyk.out", "w", stdout);
	long long n, ans = 0;
	cin >> n >> m >> p;
    for (int i = 0; i < (1<<m); ++i)
    {
    		dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i){
    	for (int j = 0; j < (1<<m); ++j){
    		for (int k = 0; k < (1<<m); ++k){
    			if (check(j, k)){
    				dp[i][j] += dp[i-1][k];
    				dp[i][j]%= p;
    			}
    		}
    	}
    }                     /*
    for (int i = 0; i < 10; ++i){
    	for (int j = 0; j < 32; ++j)
    		cout << dp[i][j] << " ";
    		cout << endl;
    }                   */
    for (int j = 0; j < (1<<m); ++j){
    		ans+= dp[n-1][j];
    		ans %= p;
    		}
    		cout << ans%p;

	
	return 0;
}


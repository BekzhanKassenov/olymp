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
const int maxn = 5010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

char s[maxn], t[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
    scanf("%s%s", s, t);

    if (strlen(s) > strlen(t)) {
    	cout << 0;
    	return 0;
    }

    int lens = strlen(s), lent = strlen(t);

    int ans = 0;

    for (int i = 0; i + lens <= lent; i++) {
    	int cnt = 0;
    	for (int j = 0; j < lens; j++)
    		if (t[i + j] != s[j])
    			cnt++;

  		if (cnt == 1)
  			ans++;
    }

    cout << ans;

	return 0;
}

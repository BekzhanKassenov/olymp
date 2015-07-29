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

int gcd(int a, int b) {
	if (!a && !b)
		return 1;

	if (!a || !b)
		return a + b;

	return gcd(b % a, a);	
}

int lcm(int a, int b) {
	return (a / gcd(a, b) * b);
}

int a[110][110], sz, n;
long long ans[110] = {1};

bool check_gcd(int val, int i) {
	for (int j = 0; j < n; j++) {
		if (i != j && gcd(val, ans[j]) != a[i][j])
			return false;
	}

	return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
    	for (int j = 1; j <= n - i - 1; j++) {
    		cin >> a[i][i + j];
    		a[i + j][i] = a[i][i + j];
    	}
    	a[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
    	int cur = 1;

    	for (int j = 0; j < n; j++)
    		cur = lcm(cur, a[i][j]);

    	ans[i] = cur;
    }

    cout << ans[0] << ' ';

    for (int i = 1; i < n; i++) {
    	if (ans[i] <= ans[i - 1]) {
    		int appr = ans[i - 1] / ans[i] + 1;

    		while (true) {
    			int tmp = appr * ans[i];

    			if (check_gcd(tmp, i)) {
    				ans[i] = tmp;
    				break;
    			}
    			appr++;
    		}
    	}

    	cout << ans[i] << ' ';
    }

	return 0;	
}

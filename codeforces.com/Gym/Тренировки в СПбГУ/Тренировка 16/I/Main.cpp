/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[240][240], n, d[240], cur;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
    	d[i] = i;
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
    	}
    	cur += a[i][i];    	
    }
    bool was = true;
    while(was) {
    	was = false;
    	for (int i = 1; i < n; i++) {
    		for (int j = 0; j < i; j++) {
    			int r1 = d[i], r2 = d[j];
    			if (a[r1][r1] + a[r2][r2] > a[r1][r2] + a[r2][r1]) {
    				was = true;
    				cur -= (a[r1][i] + a[r2][j] - a[r1][j] - a[r2][i]);
    				swap(d[i], d[j]);
    			}
    		}
    	}
    }
    cout << cur << endl;
    for (int i = 0; i < n; i++) {
    	cout << d[i]+1 << " " << i+1 << endl;
    }
    return 0;
}

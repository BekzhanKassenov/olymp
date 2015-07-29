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
const int MAXN = 120 + 13;

template <typename T>
inline T sqr(T n) {
    return n * n;
}                                                                                        

int kom, x, y, z, k, __x1, __y1, __z1, __x2, __y2, __z2;
int n, t[MAXN][MAXN][MAXN];

void update (int x, int y, int z, int knt) {
	for (int i = x; i <= n; i = i | (i + 1))	
		for (int j = y; j <= n; j = j | (j + 1))
			for (int k = z; k <= n; k = k | (k + 1))
				t[i][j][k] += knt;
}

int sum (int __x1, int __y1, int __z1) {
    int res = 0;
	for (int i = __x1; i >= 0; i = (i & (i + 1)) - 1)	
		for (int j = __y1; j >= 0; j = (j & (j + 1)) - 1)
			for (int k = __z1; k >= 0; k = (k & (k + 1)) - 1)
				res += t[i][j][k];
	return res;
}

int sum (int __x1, int __y1, int __z1, int __x2, int __y2, int __z2) {
    __x1--, __y1--, __z1--;
	return sum (__x2, __y2, __z2) - 
			sum (__x1, __y2, __z2) - sum (__x2, __y1, __z2) + sum (__x1, __y1, __z2) - 
				sum (__x2, __y2, __z1) + sum (__x1, __y2, __z1) + sum (__x2, __y1, __z1) - 
					sum (__x1, __y1, __z1);			

}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

	cin >> n;
	  
	while (cin >> kom) {
		if (kom == 3) 
			break;

		if (kom == 1) {
			cin >> x >> y >> z >> k;
						
			update (x + 1, y + 1, z + 1, k);
	
		} else if (kom == 2) {
			cin >> __x1 >> __y1 >> __z1 >> __x2 >> __y2 >> __z2;		

			cout << sum (__x1 + 1, __y1 + 1, __z1 + 1, __x2 + 1, __y2 + 1, __z2 + 1) << endl;
		}
	}
    
    return 0;
}

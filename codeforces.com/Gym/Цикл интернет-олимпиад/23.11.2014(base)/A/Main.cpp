/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "capital"

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

int sum, n;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &sum, &n);

 	vector <int> res;
 	for (int i = 0; i < n; i++) {
 	 	if (sum >= 9) {
 	 	 	res.push_back(9);
 	 	 	sum -= 9;
 	 	} else {
 	 	 	res.push_back(sum);
 	 	 	sum = 0;
 	 	}
 	}

 	if (sum > 0) {
 	 	puts("-1");
 	} else {
 	 	for (size_t i = 0; i < res.size(); i++)
 	 		printf("%d", res[i]);
 	 	puts("");
 	}
    
    return 0;
}

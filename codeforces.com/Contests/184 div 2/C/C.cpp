/****************************************
**     Solution by Bekzhan Kassenov    **
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

map <int, int> Map;
vector <pair <int, int> > vec;
int n, x, cnt, mx;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &x);

	 	Map[x]++;
	}

	for (map <int, int> :: iterator it = Map.begin(); it != Map.end(); it++) {
	 	int val = it -> second;
	 	Map[it -> first] = 0;

	 	for (int i = 0; val; i++) {
	 	 	if (val & 1) {
	 	 	 	Map[it -> first + i]++;
	 	 	}

	 	 	val >>= 1;
	 	}

	 	if (Map[it -> first] != 0) {
	 		cnt++;
	 		mx = it -> first;
	 	}
	}

	printf("%d", mx - cnt + 1);

    return 0;
}

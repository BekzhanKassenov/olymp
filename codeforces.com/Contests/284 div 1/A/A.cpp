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
const int MAXN = 1 << 16;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <pair <int, int> > res;
int n;
int s[MAXN], deg[MAXN];
queue <int> q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
		scanf("%d%d", &deg[i], &s[i]);
		if (deg[i] == 1) {
		 	q.push(i);
		}
    }

    while (!q.empty()) {
     	int v = q.front();
     	q.pop();

     	if (deg[v] == 0)
     		continue;

     	int par = s[v];
     	s[par] ^= v;
     	deg[par]--;

     	if (deg[par] == 1) {
     	 	q.push(par);
     	}

     	res.push_back(make_pair(v, par));
    }

    printf("%d\n", res.size());

    for (size_t i = 0; i < res.size(); i++) {
     	printf("%d %d\n", res[i].first, res[i].second);
    }
    
    return 0;
}

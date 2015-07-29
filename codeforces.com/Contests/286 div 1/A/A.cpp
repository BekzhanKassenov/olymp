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
const int MAXN = 30001;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, d, x;
int cnt[MAXN];
int sum[MAXN + 1];
int ans;
map <int, int> dist[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &d);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		cnt[x]++;
	}

    for (int i = MAXN - 1; i >= 0; i--) {
    	sum[i] = sum[i + 1] + cnt[i];
    }

    dist[d][d] = 0;

    for (int i = 0; i < MAXN; i++) {
     	for (map <int, int> :: iterator it = dist[i].begin(); it != dist[i].end(); it++) {
     	 	int s = it -> second;
     	 	int len = it -> first;

     	 	if (len <= 2) {
     	 	 	ans = max(ans, s + sum[i]);
     	 	 	continue;
     	 	}

     	 	if (len == 3) {
     	 	 	int temp = cnt[i];
     	 	 	if (i + 2 < MAXN) {
     	 	 	 	temp += sum[i + 2];
     	 	 	}

     	 	 	ans = max(ans, s + temp);
     	 	 	continue;
     	 	}

     	 	ans = max(ans, s + cnt[i]);

     	 	for (int j = -1; j <= 1; j++) {
				int next_pos = i + len + j;
				if (next_pos < MAXN && len + j < 2 * d && dist[next_pos][len + j] < s + cnt[i]) {
				 	 dist[next_pos][len + j] = s + cnt[i];
				}
    		}
     	}
    }

	printf("%d\n", ans);
    return 0;
}

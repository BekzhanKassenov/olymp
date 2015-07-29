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
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN];
char s[MAXN][MAXN];
vector <int> nums, poss;
bool used[MAXN];

void dfs(int v) {
 	nums.push_back(a[v]);
 	poss.push_back(v);
 	used[v] = true;

 	for (int i = 0; i < n; i++) {
 	 	if (!used[i] && s[v][i] == '1')
 	 		dfs(i);
 	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d\n", &a[i]);

	for (int i = 0; i < n; i++) {
	 	gets(s[i]);
	}

	for (int i = 0; i < n; i++) {
	 	if (!used[i]) {
			dfs(i);

			sort(all(nums));
			sort(all(poss));

			for (size_t i = 0; i < nums.size(); i++) {
			 	a[poss[i]] = nums[i];
			}

			nums.clear();
			poss.clear();
	 	}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

    return 0;
}

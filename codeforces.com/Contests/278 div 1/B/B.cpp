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
const int INF = 2000 * 1000 * 1000 + 1000;
const int MAXLEV = 17;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int table_max[MAXLEV][MAXN];
int table_min[MAXLEV][MAXN]; // Sparse tables
int level[MAXN]; // level[i] is logarythm of i
int a[MAXN], n, S, L;
int mem[MAXN], *dp;

inline void build() {
    for (int i = 0; i < n; i++) {
        table_max[0][i] = a[i];
        table_min[0][i] = a[i];
    }

    dp = mem + 1;

    for (int i = 2; i <= n; i++)
    	level[i] = level[i >> 1] + 1;

    for (int l = 1; l <= level[n]; l++) {
        int prev_power = 1 << (l - 1); // 2 ^ (l - 1)

        for (int i = 0; i < n; i++) {
            table_max[l][i] = table_max[l - 1][i];
            table_min[l][i] = table_min[l - 1][i];

            if (i + prev_power < n) {
                table_max[l][i] = max(table_max[l][i], table_max[l - 1][i + prev_power]);
                table_min[l][i] = min(table_min[l][i], table_min[l - 1][i + prev_power]);
            }
        }
    }
}

inline bool check(int l, int r) {
    int lev = level[r - l];

    int mini = min(table_min[lev][l], table_min[lev][r - (1 << lev)]);
    int maxi = max(table_max[lev][l], table_max[lev][r - (1 << lev)]);

    return maxi - mini <= S;
}

int bin_search(int pos) {
    int ans = -1, l = pos, r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(pos, mid + 1)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

vector <int> insert[MAXN];
vector <int> erase[MAXN];
multiset <int> current;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &S, &L);
    
    for (int i = 0; i < n; i++) {
     	scanf("%d", &a[i]);
    }

    build();
    dp[-1] = 0;

    for (int i = 0; i < n; i++) {
     	for (size_t j = 0; j < insert[i].size(); j++) {
     	 	current.insert(insert[i][j]);
     	}

     	//cerr << erase[i].size() << endl;
     	for (size_t j = 0; j < erase[i].size(); j++) {
     	 	current.erase(current.find(erase[i][j]));
     	}

     	//cerr << "ASD" << endl;

     	if (L == 1) {
     		dp[i] = min(INF, dp[i - 1] + 1);
     		current.insert(dp[i - 1] + 1);
     	} else
     		dp[i] = INF;
     		    	
     	if (!current.empty()) {
     		dp[i] = min(dp[i], *current.begin());
     	}

     	//cerr << dp[i] << ' ';
     	
     	int val = dp[i - 1] + 1;

     	int lnxt = i + L - 1;

     	if (lnxt > n - 1 || !check(i, lnxt + 1) || val >= INF)
     		continue;

     	int rnxt = bin_search(i);
     	

     	//cerr << i << ' ' << lnxt << ' ' << rnxt << endl;

     	insert[lnxt].push_back(val);
     	erase[rnxt + 1].push_back(val);
    }

    if (dp[n - 1] == INF)
    	puts("-1");
    else
    	printf("%d\n", dp[n - 1]);

    return 0;
}

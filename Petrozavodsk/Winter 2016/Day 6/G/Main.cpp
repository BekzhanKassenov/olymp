/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXB = 50;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int getBucket(long long num) {
    int ans = 0;
    while (num > 0) {
        ans++;
        num >>= 1;
    }

    return ans;
}

int n;
multiset <long long> bucket[MAXB];
long long bucketSum[MAXB];
long long f[MAXN];

void add(long long val) {
    int b = getBucket(val);
    bucket[b].insert(val);
    bucketSum[b] += val;
}

void remove(long long val) {
    int b = getBucket(val);
    bucket[b].erase(bucket[b].find(val));
    bucketSum[b] -= val;
}

int query() {
    long long sum = 0;
    int ans = 0;
    for (int i = 0; i < MAXB; i++) {
        if (!bucket[i].empty()) {
            long long val1 = *bucket[i].begin();
            if (val1 >= sum) {
                ans++;
            }

    //        cerr << i << ' ' << val1 << endl;

            if (bucket[i].size() > 1u) {
                auto iter = bucket[i].begin();
                iter++;

                long long val2 = *iter;

    //            cerr << i << ' ' << val2 << endl;

                if (val2 >= val1 + sum) {
                    ans++;
                }
            }
        }

        sum += bucketSum[i];
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf(I64, &f[i]);
        add(f[i]);
    }

    printf("%d\n", query());

    int m;
    scanf("%d", &m);

    while (m--) {
        int k;
        long long val;
        scanf("%d" I64, &k, &val);
        
        remove(f[k]);
        f[k] = val;
        add(f[k]);

        printf("%d\n", query());
    }
    
    return 0;
}

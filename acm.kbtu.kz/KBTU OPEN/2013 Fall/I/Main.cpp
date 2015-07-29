/******************************************
**          Solution by NU #2            **
******************************************/

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define File "lcm"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T x) {
    return (x * x);
}

bool make(int* cnt, int maxn, ll n) {
    cnt[0] = cnt[1] = 0;
    for (int i = 2; i <= maxn; i++) {
        cnt[i] = 0;
        while (n % i == 0) {
            cnt[i]++;
            n /= i;
        }
    }

    if (n > 1)
        return false;

    return true;    
}

int cnt[65][65];
ull mask[65], maskm;
int cntm[65];
vector <int> cur;
int len;

ll rec(ull msk, int pos) {
    if (pos == len)
        return (msk == maskm);

    if (msk == maskm)
        return (1ull << (len - pos));

    if ((msk | mask[cur[pos]]) == msk)
        return 2ull * rec(msk, pos + 1);

    ll ans = rec(msk, pos + 1) + rec(msk | mask[cur[pos]], pos + 1);
    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n; 
        ll m;
        scanf("%d%I64d", &n, &m);

        maskm = 0;

        if (!make(cntm, n, m)) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 1; i <= n; i++)
            if (cntm[i])
                maskm |= (1ll << (i - 1));

        ll ans = 1;

        cur.clear();

        for (int i = 2; i <= n; i++) {
            if (m % i == 0) {
                make(cnt[i], n, i);

                mask[i] = 0;
                bool flag = false;

                for (int j = 2; j <= n; j++) {
                    if (cnt[i][j] && cnt[i][j] == cntm[j]) {
                        flag = true;
                        mask[i] |= (1ull << (j - 1));
                    }
                }

                if (flag)
                    cur.push_back(i);
                else
                    ans++;  
            }
        }

        len = cur.size();
        ll ans1 = rec(0ull, 0);

        ans1 *= (1ll << ans);
        cout << ans1 << endl;
    }

    return 0;
}

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
const int BASE = 11;
const int MAXN = 6;
const int MAXM = 21;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ostream& operator << (ostream& out, const vector <int>& vec) {
    cout << '(';
    for (size_t i = 0; i + 1 < vec.size(); i++) {
        out << vec[i] << ", ";
    }
    out << vec.back() << ")";
    return out;
}

int hash(const vector <int>& vec) {
    int result = 0;

    for (size_t i = 0; i < vec.size(); i++) {
        result *= BASE;
        result += vec[i];
    }

    return result;
}

int a[MAXN], b[MAXM];
int n, m;
vector <int> masks[4];
bitset <100000> dp[MAXM + 2][1 << MAXN];
bitset <100000> calced[MAXM + 2][1 << MAXN];
int ans[MAXM];

inline bool check(int mask, int bit) {
    return (mask & (1 << bit)) > 0;
}

inline void add(int mask) {
    int cnt = mask & 1;

    for (int i = 1; i < n; i++) {
        if (!check(mask, i - 1) && check(mask, i)) {
            cnt++;
        }
    }

    masks[cnt].push_back(mask);
}

vector <int> vec;
bool go(int pos, int mask) {
    ans[pos] = mask;
    int h = hash(vec);
    
    if (h < 0) {
        return false;
    }

    if (calced[pos][mask][h]) {
        return dp[pos][mask][h];
    }

    calced[pos][mask][h] = true;
    bool result = false;
    
    if (pos == 0) {
        for (int i = 0; i < n; i++) {
            if (check(mask, i)) {
                vec[i]--;
            }
        }

        result = true;
        for (int i = 0; i < n; i++) {
            if (vec[i] != 0) {
                result = false;
            }   
        }

        for (int i = 0; i < n; i++) {
            if (check(mask, i)) {
                vec[i]++;
            }
        }

        dp[pos][mask][h] = result;
        return result;
    }

    for (size_t i = 0; i < masks[b[pos - 1]].size() && !result; i++) {
        int prevmask = masks[b[pos - 1]][i];

        for (int j = 0; j < n; j++) {
            if (!check(prevmask, j) && check(mask, j)) {
                vec[j]--;
            }
        }

        if (go(pos - 1, prevmask)) {
            result = true;
        }

        for (int j = 0; j < n; j++) {
            if (!check(prevmask, j) && check(mask, j)) {
                vec[j]++;
            }
        }
    }
    
    dp[pos][mask][h] = result;
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    double start = clock();
#endif
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < (1 << n); i++) {
        add(i);
    }

    vec = vector <int> (a, a + n);
    go(m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(ans[j], i)) {
                putchar('*');
            } else {
                putchar('.');
            }
        }

        putchar('\n');
    }

#ifndef ONLINE_JUDGE
    cerr << "Time: " << (clock() - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

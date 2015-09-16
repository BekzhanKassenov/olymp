/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "high"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 50010;
const int fullMask = (1 << 5) - 1;
const int BASE = 63;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
string s[MAXN];
map <long long, int> cnt[1 << 5];
long long ans[6];
long long str[MAXN][1 << 5];
int C[10][10];

inline int code(char c) {
    if (isdigit(c)) {
        return c - '0';
    }

    if (islower(c)) {
        return 10 + c - 'a';
    }

    return 36 + c - 'A';
}

inline long long _hash(const string& s, int mask) {
    long long res = 0;

    for (size_t i = 0; i < s.size(); i++) {
        if (mask & (1 << i)) {
            res *= BASE;
            res += code(s[i]);
        }
    }

    return res;
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) { 
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;

    getline(cin, s[0]);

    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << 5); mask++) {
            str[i][mask] = _hash(s[i], mask);
            cnt[mask][str[i][mask]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << 5); mask++) {
            cnt[mask][str[i][mask]]--;
        }

        for (int mask = 0; mask < (1 << 5); mask++) {
            int num = __builtin_popcount(mask);

            ans[num] += cnt[mask][str[i][mask]];
        }
    }

    for (int i = 5; i >= 0; i--) {
        cout << ans[i] << ' ';
        for (int j = i - 1; j >= 0; j--) {
            ans[j] -= ans[i] * C[i][j];
        }
    }
    cout << endl;

    return 0;
}

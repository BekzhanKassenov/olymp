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

int code(char c) {
    if (isdigit(c)) {
        return c - '0';
    }

    if (islower(c)) {
        return 10 + c - 'a';
    }

    return 36 + c - 'A';
}

long long _hash(const string& s) {
    long long res = 0;
    for (char c: s) {
        res *= BASE;
        res += code(c);
    }

    return res;
}

string get(const string& s, int mask) {
    string res;
    for (int i = 0; i < 5; i++) {
        if (mask & (1 << i)) {
            res += s[i];
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << 5); mask++) {
            str[i][mask] = _hash(get(s[i], mask));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << 5); mask++) {
            cnt[mask][str[i][mask]]++;
        }
    }

    /*
    for (int mask = 0; mask < (1 << 5); mask++) {
        printf("%d:", mask);
        for (auto it: cnt[mask]) {
            printf(" (%s, %d)", it.first.c_str(), it.second);
        }
        puts("");
    }
    */

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << 5); mask++) {
            cnt[mask][str[i][mask]]--;
        }

        for (int mask = 0; mask < (1 << 5); mask++) {
            int omask = fullMask ^ mask;
            int num = __builtin_popcount(omask);

            ans[num] += cnt[mask][str[i][mask]];
            for (int submask = omask; submask > 0; submask = (submask - 1) & omask) {
                long long cur = str[i][mask | submask];

                if (__builtin_popcount(submask) % 2 == 0) {
                    ans[num] += cnt[mask | submask][cur];
                } else {
                    ans[num] -= cnt[mask | submask][cur];
                }
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}

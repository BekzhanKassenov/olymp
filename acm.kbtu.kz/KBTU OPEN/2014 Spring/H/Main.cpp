/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "pal"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

char s[maxn];
int n, ans;
bool flag = true;

void solve(int l, int r) {
    if (l >= r)
        return;

    if (s[l] != s[r]) {
        bool fl = false;

        for (int i = l + 1; i < r && !fl; i++) {
            if (s[i] == s[l]) {
                swap(s[i], s[r]);
                fl = true;
            } else if (s[i] == s[r]) {
                swap(s[i], s[l]);
                fl = true;
            }
        }
        ans += fl;
        flag &= fl;
    }

    solve(l + 1, r - 1);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(s);
    n = strlen(s);

    solve(0, n - 1);

    if (!flag) {
        cout << -1;
        return 0;
    }

    cout << ans;

    return 0;
}

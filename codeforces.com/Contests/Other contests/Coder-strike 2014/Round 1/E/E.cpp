/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

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
const int maxn = 1000010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, pos;
char s[maxn];
ll cnt_l, cnt_r, res;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    gets(s);

    n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '@') {
            pos = i - 1;

            cnt_l = 0, cnt_r = 0;

            while (pos >= 0 && (isdigit(s[pos]) || isalpha(s[pos]) || s[pos] == '_')) {
                if (isalpha(s[pos]))
                    cnt_l++;

                pos--;
            }

            pos = i + 1;

            while (pos < n && (isdigit(s[pos]) || isalpha(s[pos]))) {
                pos++;
            }

            if (s[pos] == '.' && pos - i > 1) {
                pos++;

                while (pos < n && isalpha(s[pos])) {
                    pos++;
                    cnt_r++;
                }
            }

            res += cnt_l * cnt_r;
        }
    }

    printf("%I64d", res);
    
    return 0;
}

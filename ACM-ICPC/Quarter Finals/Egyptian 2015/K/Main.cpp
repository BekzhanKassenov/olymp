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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;

int num[MAXN];
int cnt[210];
int n;
ull a, b;
int p;

void convert(ull a, ull b, int n) {
    a *= 10;

    for (int i = 0; i < n; i++) {
        for (int dig = 9; dig >= 0; dig--) {
            if (b * dig <= a) {
                num[i] = dig;
                a -= b * dig;
                a *= 10;
                break;
            }
        }
    }
}

void clear() {
    for (int i = 0; i < p; i++) {
        cnt[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        cin >> a >> b >> n >> p;
        clear();
        convert(a, b, n);

        reverse(num, num + n);

        long long ans = 0;

        if (p == 2 || p == 5) {
            for (int i = 0; i < n; i++) {
                if (num[i] % p == 0) {
                    ans += (n - i);
                }
            }

            cout << ans << endl;
            continue;
        }

        int modulo = 0;
        int power = 1;

        for (int i = 0; i < n; i++) {
            modulo += power * num[i];
            power *= 10;

            modulo %= p;
            power %= p;

            ans += cnt[modulo];
            if (modulo == 0) {
                ans++;
            }

            cnt[modulo]++;
        }

        cout << ans << endl;
    }

    return 0;
}

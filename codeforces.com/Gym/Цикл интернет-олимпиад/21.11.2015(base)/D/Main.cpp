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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int mem[1010][1010];
bool asked[1010][1010];
int cnt;

int ask(int a, int b) {
#ifdef ONLINE_JUDGE
    if (asked[a][b]) {
        return mem[a][b];
    }

    assert(cnt++ < 40000);
    asked[a][b] = true;
    asked[b][a] = true;
    cout << "1 " << a << ' ' << b << endl << flush;
    cin >> mem[a][b];

    mem[b][a] = -mem[a][b];
    return mem[a][b];
#else
    static vector <int> test{2, 1, 1};
    if (test[a - 1] < test[b - 1]) {
        return -1;
    }

    if (test[a - 1] == test[b - 1]) {
        return 0;
    }

    return 1;
#endif
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    auto comp = [](int a, int b) {
        ask(a, b);
        ask(a, b);

        return ask(a, b) == -1;
    };

    sort(all(a), comp);

    int ans = 1;
    for (int i = 0; i + 1 < n; i++) {
        if (ask(a[i], a[i + 1]) != 0) {
            ans++;
        }
    }

    cout << "2 " << ans << endl << flush;

    return 0;
}

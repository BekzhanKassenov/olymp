/****************************************
**          Solution by NU #2          **
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
const int MAXN = 100000 + 13;


template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, s, ans;
pair <int, int > a[MAXN];
set <int > bought;                                                                                                

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;                                          
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        if (s >= a[i].first && !bought.count(a[i].second)) {
            s -= a[i].first;
            ans++;
            bought.insert(a[i].second);
        }
    }

    cout << ans;

    return 0;
}

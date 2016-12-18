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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
int suffsum[MAXN];
vector <int> divs[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        suffsum[a[i]]++;
    }

    sort(a, a + n);

    for (int i = MAXN - 2; i >= 0; i--) {
        suffsum[i] += suffsum[i + 1];
    }

    n = unique(a, a + n) - a;
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        vector <int> vec;
        for (int j = a[i]; j < MAXN; j += a[i]) {
            vec.push_back(j);
        }

        reverse(all(vec));

        long long sum = 0;
        long long res = 0;

        for (int d: vec) {
            res += (suffsum[d] - sum) * d;
            sum = suffsum[d];
        }   

        ans = max(ans, res);
    }

    cout << ans << endl;

    return 0;
}

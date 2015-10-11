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
const int BSIZE = 5;//256;
const int MAXN = BSIZE * BSIZE;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[MAXN];

int n, k;

int get() {
    vector <int> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back(a[i]);
    }

    sort(all(temp));

    return temp[n / 2];
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;

        for (int i = l - 1; i < r; i++) {
            a[i]++;
        }

        cout << get() << endl;
    }
    
    return 0;
}

/******************************************
**          Solution by NU #2            **
******************************************/

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define File "arrangement"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T x) {
    return (x * x);
}

bool used[50];
int sum[1 << 20];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int n;
    
    cin >> n;

    vector <int> a(n);

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    for (int mask = 1; mask < (1 << n); mask++) {
        int s = 0;
        for (int i = 0; i < n; i++) 
            if (mask & (1 << i))
                s += a[i];

        int ans = INF;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                ans = min(ans, sum[mask - (1 << i)]);
        }

        sum[mask] = abs(s) + ans;
    }   

    cout << sum[(1 << n) - 1];

    return 0;
}

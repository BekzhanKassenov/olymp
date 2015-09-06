/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "acm"

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

int n, m;
int a[11];

void print(int a) {
    cout << "(10";

    for (int i = 0; i < a; i++) {
        cout << "-1";
    }
    cout << ')';
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    print(a[0]);
    for (int i = 1; i < n; i++) {
        cout << '*';
        print(a[i]);
    }

    cout << "=0" << endl;

    return 0;
}

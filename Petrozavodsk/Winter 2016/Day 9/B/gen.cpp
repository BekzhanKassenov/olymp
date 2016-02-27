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
const int MAXN = 50;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    srand(time(NULL));

    int a = rand() % 15 + 1;
    int b = rand() % 15 + 1;
    int n = a + b;
    int m = min(rand() % 40 + 1, (n * (n - 1)) / 4);
    cout << a + b << ' ' << m << endl;

    vector <int> c1, c2;

    for (int i = 1; i <= a; i++) {
        c1.push_back(i);
    }

    for (int i = a + 1; i <= a + b; i++) {
        c2.push_back(i);
    }

    set <pair <int, int> > Set;
    for (int i = 0; i < m; i++) {
        while (true) {
            int p1 = c1[rand() % c1.size()];
            int p2 = c2[rand() % c2.size()];

            if (!Set.count(make_pair(p1, p2))) {
                cout << p1 << ' ' << p2 << endl;
                Set.insert(make_pair(p1, p2));
                break;
            }
        }
    }

    return 0;
}

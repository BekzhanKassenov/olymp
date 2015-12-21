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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

set <int> Set;

int main() {
    srand(time(NULL));

    int n = rand() % 1000 + 1;
    cout << n << endl;

    int last = 1;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        do {
            ok = false;
            char type = "FBO"[rand() % 3];

            if (type == 'F' || type == 'B') {
                cout << type << endl;
                Set.insert(last++);
                ok = true;
            } else {
                if (!Set.empty()) {
                    auto it = Set.begin();
                    int dist = rand() % Set.size();
                    ok = true;
                    while (dist--) {
                        it++;
                    }

                    cout << type << ' ' << *it << endl;
                    Set.erase(it);
               }
            }
        } while (!ok);
    }

    return 0;
}

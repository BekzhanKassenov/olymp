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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, b;
map <string, vector <pair <int, int> > > Map;

bool check(int q) {
    int cost = 0;

    for (const auto& it: Map) {
        int mn = INF;
        
        for (const auto& p: it.second) {
            if (p.second >= q) {
                mn = min(mn, p.first);
            }
        }

        if (mn == INF) {
            return false;
        }

        cost += mn;
    }

    return cost <= b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        cin >> n >> b;

        Map.clear();

        for (int i = 0; i < n; i++) {
            string type, name;
            int price, qual;

            cin >> type >> name >> price >> qual;

            Map[type].emplace_back(price, qual);
        }

        int l = 0, r = INF;

        int ans = INF;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (check(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}

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

struct Shoe {
    string company;
    int size;
    string color;

    bool operator < (const Shoe& s) const {
        if (company != s.company) {
            return company < s.company;
        }

        if (size != s.size) {
            return size < s.size;
        }

        return color < s.color;
    }
};

map <Shoe, int> L, R;
int n;
Shoe cur;
char side;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cur.company >> cur.size >> cur.color >> side;

        if (side == 'L') {
            L[cur]++;
        } else {
            R[cur]++;
        }
    }

    int ans = 0;
    for (const auto& it: L) {
        ans += min(it.second, R[it.first]);
    }

    cout << ans << endl;
    
    return 0;
}

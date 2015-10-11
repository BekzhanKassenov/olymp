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
const int MAXN = 20;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum DIR {
    SW,
    SE,
    NE,
    NW
};

enum EVENT {
    OPEN,
    CLOSE
};

struct Triangle {
    int l, r;
    int dir;
    int len;
    int diffl, diffr;

    Triangle(int l = 0, int r = 0, int dir = 0, int len = 0) : l(l), r(r), dir(dir), len(len) { }
};

int n, k;
vector <Triangle> vec[MAXN];
vector <Triangle> cur;
bitset <MAXN> bit;

bool inc(Triangle& t) {
    if (t.len == 0) {
        for (int i = t.l + t.diffl; i <= t.r + t.diffr; i++) {
            bit.flip(i);
        }
        return false;
    }

    switch (t.dir) {
        case SW:
            bit.flip(t.r);
            t.r++;  
            t.diffr = -1;
            t.diffl = 0;
            break;
        case SE:
            bit.flip(t.r);
            t.r--;
            t.diffr = 1;
            t.diffl = 0;
            break;
        case NE:
            t.l--;
            bit.flip(t.l);
            t.diffr = 0;
            t.diffl = -1;
            break;
        case NW:
            bit.flip(t.l);
            t.l++;
            t.diffr = 0;
            t.diffl = 1;
            break;
        default:
            break;
    }

    t.len--;

    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d%d", &n, &k) == 2) {
        for (int i = 0; i <= n; i++) {
            vec[i].clear();
        }

        for (int i = 0; i < k; i++) {
            int x, y, d, l;

            scanf("%d%d%d%d", &y, &x, &l, &d);

            switch (d) {
                case SW:
                    vec[x - l + 1].push_back(Triangle(y, y, d, l));
                    break;
                case SE:
                    vec[x].push_back(Triangle(y, y + l - 1, d, l));
                    break;
                case NE:
                    vec[x].push_back(Triangle(y - l + 1, y, d, l));
                    break;
                case NW:
                    vec[x - l + 1].push_back(Triangle(y, y, d, l));
                    break;
                default:
                    break;
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            vector <Triangle> temp;

            for (auto x: cur) {
                if (inc(x)) {
                    temp.push_back(x);
                }
            }

            for (auto x: vec[i]) {
                temp.push_back(x);

                bitset <MAXN> temp;

                for (int i = 0; i < x.r - x.l; i++) {
                    temp.set(i);
                }

                temp <<= x.l - 1;

                bit ^= temp;
            }

            cur = temp;

            cout << bit << endl;

            ans += bit.count();
        }

        printf("%d\n", ans);
    }
    
    return 0;
}                       

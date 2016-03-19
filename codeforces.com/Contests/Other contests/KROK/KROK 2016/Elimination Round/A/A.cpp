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
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <string> a(2), b(2);
map <vector <string>, bool > Map;

bool ok(int i, int j) {
    return 0 <= i && i < 2 &&
           0 <= j && j < 2;
}

bool go(const vector <string>& vec) {
    if (vec == b) {
        return true;
    }

    if (Map.count(vec)) {
        return Map[vec];
    }

    Map[vec] = false;

    int si = -1, sj = -1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (vec[i][j] == 'X') {
                si = i, sj = j;
                break;
            }
        }
    }

    for (int k = 0; k < 4; k++) {
        int ti = si + di[k];
        int tj = sj + dj[k];

        if (ok(ti, tj)) {
            vector <string> temp(vec);
            swap(temp[si][sj], temp[ti][tj]);

            if (go(temp)) {
                Map[vec] = true;
                return true;
            }
        }
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];


    if (go(a)) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}

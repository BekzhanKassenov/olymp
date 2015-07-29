#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

int main() {
    //assert(freopen("bipartite.in", "r", stdin));
    //assert(freopen("bipartite.out", "w", stdout));

    vector <pair <int, int> > a;
    a.push_back(make_pair(0, 2));
    a.push_back(make_pair(0, 3));
    a.push_back(make_pair(1, 2));
    a.push_back(make_pair(1, 3));

    int ans = 0;

    for (int mask = 1; mask < (1 << 4); mask++) {
        int g[4][4];
        memset(g, 0, sizeof g);

        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                g[a[i].first][a[i].second] = g[a[i].second][a[i].first] = 1;
            }
        }

        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (g[i][k] && g[k][j])
                        g[i][j] = true;
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j && !g[i][j])
                    flag = false;
            }
        }

        ans += flag;

        if (flag) {
            for (int i = 0; i < 4; i++) {
                if (mask & (1 << i))
                    cout << a[i].first + 1 << ' ' << a[i].second + 1 << endl;
            }
            cout << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    vector <tuple<int, int, int> > ans;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i] && b[i] != 0) {
            ans.emplace_back(b[i], 1, i);
            b[i] = 0;
            found = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] == d[i] && c[i] != 0) {
            ans.emplace_back(c[i], 4, i);
            c[i] = 0;
            found = true;
        }
    }

    if (k == 2 * n && !found) {
        cout << -1 << endl;
        return 0;
    }

    while (true) {
        bool foundCar = false;
        for (int pos = n; pos >= 1; pos--) {
            if (c[pos] == 0) {
                continue;
            }

            foundCar = true;
            for (int i = pos; i < n; i++) {
                if (c[i] == d[i]) {
                    ans.emplace_back(c[i], 4, i);
                    c[i] = 0;
                    break;
                }
                if (c[i + 1] != 0) {
                    break;
                }

                ans.emplace_back(c[i], 3, i + 1);
                c[i + 1] = c[i];
                c[i] = 0;
            }
        }
        if (c[n] != 0) {
            if (c[n] == d[n]) {
                ans.emplace_back(c[n], 4, n);
                c[n] = 0;
            } else if (b[n] == 0) {
                ans.emplace_back(c[n], 2, n);
                b[n] = c[n];
                c[n] = 0;
            }
        }

        for (int pos = 1; pos <= n; pos++) {
            if (b[pos] == 0) {
                continue;
            }

            foundCar = true;
            for (int i = pos; i > 1; i--) {
                if (a[i] == b[i]) {
                    ans.emplace_back(b[i], 1, i);
                    b[i] = 0;
                    break;
                }
                if (b[i - 1] != 0) {
                    break;
                }
                ans.emplace_back(b[i], 2, i - 1);
                b[i - 1] = b[i];
                b[i] = 0;
            }
        }
        if (b[1] != 0) {
            if (b[1] == a[1]) {
                ans.emplace_back(b[1], 1, 1);
                b[1] = 0;
            } else if (c[1] == 0) {
                ans.emplace_back(b[1], 3, 1);
                c[1] = b[1];
                b[1] = 0;
            }
        }

        if (!foundCar) {
            break;
        }

        /*
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << b[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << c[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << d[i] << ' ';
        }
        cout << endl << endl;
        */
    }

    cout << ans.size() << endl;
    for (const auto& tup : ans) {
        cout << get<0>(tup) << ' ' << get<1>(tup) << ' ' << get<2>(tup) << endl;
    }

    return 0;
}

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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, d, x[110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    set <int> pos;
    for (int i = 0; i < n; i++) {
        pos.insert(x[i] - d);
        pos.insert(x[i] + d);
    }

    int ans = 0;
    for (int p : pos) {
        int closest = abs(p - x[0]);
        for (int i = 1; i < n; i++) {
            closest = min(closest, abs(p - x[i]));
        }
        if (closest == d) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

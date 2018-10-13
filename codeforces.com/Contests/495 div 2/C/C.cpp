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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN], pref[MAXN];
bool used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (!used[a[i]]) {
            used[a[i]] = true;
            pref[i]++;
        }
    }

    memset(used, false, sizeof(used));
    long long ans = 0;
    for (int i = n; i > 0; i--) {
        if (!used[a[i]]) {
            ans += pref[i - 1];
            used[a[i]] = true;
        }
    }

    printf("%lld\n", ans);
    
    return 0;
}

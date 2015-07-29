#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 2 * 105000;
const long long INF = 2 * 1000 * 1000 * 1000;

void update(long long f[], int pos, long long delta) {
    for (; pos < MAXN; pos = (pos | (pos + 1)))
        f[pos] += delta;
}

long long getsum(long long f[], int pos) {
    long long res = 0;
    for (; pos > 0; pos = (pos & (pos + 1)) - 1)
        res += f[pos];
    return res;
}

long long getsum(long long f[], int l, int r) {
    return getsum(f, r) - getsum(f, l - 1);
}

int n, q;
int qt[MAXN];
int pos[MAXN], x[MAXN];
int h[MAXN];
long long vol[MAXN];
long long num[MAXN], sum[MAXN];
map <int, bool> has;
map <long long, int> id;
long long val[MAXN];
int ind;
double best;

bool can(int pos, long long vol, bool upd = false) {

    int curval = val[pos];

    long long sump = getsum(sum, 1, pos - 1);
    long long nump = getsum(num, 1, pos - 1);

    if (curval == INF) {
        if (upd)
            best = 1.0 * (sump + vol) / nump;
        return true;
    }

    long long add = 1.0 * nump * curval - sump;

    if (add < vol)
        return false;
    else {
        if (upd)
            best = 1.0 * (sump + vol) / nump;
        return true;    
    }
}


int main() {
    freopen("in","r",stdin);

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        has[h[i]] = true;   
    }

    for (int i = 1; i <= q; i++) {
        scanf("%d", &qt[i]);
        if (qt[i] == 1) {
            scanf("%d %d", &pos[i], &x[i]);
            has[x[i]] = true;
        }
        else {
            scanf("%I64d", &vol[i]);
        }
    }

    ind = 1;
    for (map <int, bool> :: iterator it = has.begin(); it != has.end(); it++) {
        int cur = it->first;
        val[ind] = cur;
        id[cur] = ind;
        ind++;
    }
    val[ind] = INF;
    id[INF] = ind;
    ind++;

    for (int i = 1; i <= n; i++) {
        update(num, id[h[i]], 1);
        update(sum, id[h[i]], h[i]);
    }

    for (int i = 1; i <= q; i++) {
        if (qt[i] == 1) {
            int prev = h[pos[i]];

            update(num, id[prev], -1);
            update(sum, id[prev], -prev);

            h[pos[i]] = x[i];

            int cur = x[i];
            update(num, id[cur], 1);
            update(sum, id[cur], cur);
        }
        else {
            best = -1;

            int l = 1, r = ind - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (can(mid, vol[i]))
                    r = mid;
                else
                    l = mid + 1;
            }

            can(l, vol[i], true);
                                    
            printf("%.12lf\n", best);
        }
    }

    return 0;
}
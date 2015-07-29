#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MP make_pair

typedef long long ll;

ll sqr(ll n) {
    return n * n;
}

ll dist(ll xx, ll yy, ll _x, ll _y) {
    return sqr(xx - _x) + sqr(yy - _y);
}

ll x, _x, y, _y;
ll x0, y0, r;
ll ans;

ll get_inters(ll l, ll r, ll yy) {
    if (yy < y || yy > _y)
        return 0ll;

    pair <int, bool> a[4];
    
    a[0] = MP(x, false);
    a[1] = MP(_x, true);

    a[2] = MP(l, false);
    a[3] = MP(r, true);

    sort(a, a + 4);

    ll res = 0;
    int bal = 0;

    for (int i = 0; i < 4; i++) {
        if (bal == 2)
            res += a[i].first - a[i - 1].first + 1;

        bal += -a[i].second + !a[i].second;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%I64d %I64d %I64d %I64d\n", &x, &y, &_x, &_y);

    scanf("%I64d %I64d %I64d\n", &x0, &y0, &r);

    ll cur_r = r;

    for (int i = 0; i <= r; i++) {
        while (dist(x0 + cur_r, y0 + i, x0, y0) > sqr(r))
            cur_r--;

        int right = x0 + cur_r;
        int left  = x0 - cur_r;

        ans += get_inters(left, right, y0 + i);
    }

    cur_r = r;

    for (int i = 1; i <= r; i++) {
        while (dist(x0 + cur_r, y0 - i, x0, y0) > sqr(r))
            cur_r--;

        int right = x0 + cur_r;
        int left  = x0 - cur_r;

        ans += get_inters(left, right, y0 - i);
    }

    printf("%I64d\n", ans);

    return 0;
}

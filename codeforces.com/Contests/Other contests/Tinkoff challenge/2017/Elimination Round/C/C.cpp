/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

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

enum EVENT {
    OPEN,
    CLOSE
};

bool can_merge(const pair <double, double>& a, const pair <double, double>& b) {
    return (a.first <= b.first && b.first <= a.second)
        || (a.first <= b.second && b.second <= a.second);
}

pair <double, double> merge(const pair <double, double>& a, const pair <double, double>& b) {
    if (a.first > b.first) {
        return merge(b, a);
    }

    if (b.second > a.second) {
        return {b.first, a.second};
    }

    return {b.first, b.second};
}

int n;
double l, r, u, d;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    cin >> l >> u >> r >> d;

    if (l > r) {
        swap(l, r);
    }

    if (d > u) {
        swap(u, d);
    }

    vector <pair <double, EVENT> > events;

    for (int i = 0; i < n; i++) {
        int x, y, vx, vy;
        cin >> x >> y >> vx >> vy;

        if (vx == 0 && vy == 0) {
            if (x < l || x > r || y < d || y > u) {
                cout << -1 << endl;
                return 0;
            }
        }

        if (vy == 0) {
            double st = (l - x) / double(vx);
            double ft = (r - x) / double(vx);
            if (st > ft) {
                cout << -1 << endl;
                return 0;
            }

            events.emplace_back(st, OPEN);
            events.emplace_back(ft, CLOSE);
        } else if (vx == 0) {
            double st = (d - y) / double(vy);
            double ft = (u - y) / double(vy);

            if (st > ft) {
                cout << -1 << endl;
                return 0;
            }

            events.emplace_back(st, OPEN);
            events.emplace_back(ft, CLOSE);
        } else {
            double st1 = (l - x) / double(vx);
            double ft1 = (r - x) / double(vx);
            double st2 = (d - y) / double(vy);
            double ft2 = (u - y) / double(vy);

            if (st1 > ft1 || st2 > ft2 || !can_merge(make_pair(st1, ft1), make_pair(st2, ft2))) {
                cout << -1 << endl;
                return 0;
            }


            pair <double, double> m{merge(make_pair(st1, ft1), make_pair(st2, ft2))};
            events.emplace_back(m.first, OPEN);
            events.emplace_back(m.second, CLOSE);
        }
    }

    sort(all(events));

    int bal = 0;
    for (const auto& event : events) {
        cerr << event.first << ' ' << event.second << endl;
        if (event.second == OPEN) {
            bal++;
        }

        if (bal == n) {
            cout << fixed << setprecision(16) << event.first << endl;
            return 0;
        }

        if (event.second == CLOSE) {
            bal--;
        }
    }

    cout << -1 << endl;
    
    return 0;
}

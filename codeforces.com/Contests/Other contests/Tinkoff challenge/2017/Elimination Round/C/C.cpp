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
const double INF = 1e40;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum EVENT {
    CLOSE,
    OPEN
};

void solve(double start0, double start1, double v0, double v1, 
           double segm0, double segm1_lower, double segm1_upper,
           vector <double>& times) {
    if (v0 == 0) {
        if (start0 == segm0 && segm1_lower <= start1 && start1 <= segm1_upper) {
            double tL = (segm1_lower - start1) / double(v1);
            double tU = (segm1_upper - start1) / double(v1);
            times.push_back(max(tL, tU));
        }
    } else {
        double t = (segm0 - start0) / double(v0);
        double end1 = start1 + v1 * t;
        if (segm1_lower <= end1 && end1 <= segm1_upper && t >= 0) {
            times.push_back(t);
        }
    }
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
            if (l < x && x < r && d < y && y < u) {
                events.emplace_back(0, OPEN);
                events.emplace_back(INF, CLOSE);
                continue;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }

        if (vx == 0) {
            if (!(l < x && x < r)) {
                cout << -1 << endl;
                return 0;
            }
        }
        
        if (vy == 0) {
            if (!(d < y && y < u)) {
                cout << -1 << endl;
                return 0;
            }
        }

        vector <double> times;
        if (l <= x && x <= r && d <= y && y <= u) {
            times.push_back(0);
        }
        solve(x, y, vx, vy, l, d, u, times);
        solve(x, y, vx, vy, r, d, u, times);

        solve(y, x, vy, vx, d, l, r, times);
        solve(y, x, vy, vx, u, l, r, times);

        sort(all(times));
        times.resize(unique(all(times)) - times.begin());

        if (times.size() < 2u) {
            cout << -1 << endl;
            return 0;
        }

        events.emplace_back(times[0], OPEN);
        events.emplace_back(times.back(), CLOSE);
    }

    sort(all(events));

    int bal = 0;
    for (const auto& event : events) {
        if (event.second == OPEN) {
            bal++;
        }

        if (event.second == CLOSE) {
            bal--;
        }

        if (bal == n) {
            cout << fixed << setprecision(16) << event.first << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}

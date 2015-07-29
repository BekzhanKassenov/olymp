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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum TYPE {
    OPEN,
    CLOSE
};

void get_union(vector <pair <int, int> >& vec) {
    vector <pair <int, TYPE> > event;

    for (size_t i = 0; i < vec.size(); i++) {
        event.push_back(make_pair(vec.first, OPEN));
        event.push_back(make_pair(vec.second, CLOSE));
    }

    sort(all(event));
    vec.clear();
    int cnt = 0;
    int open = -1;

    for (size_t i = 0; i < event.size(); i++) {
        if (event[i].second == OPEN) {
            cnt++;
            if (cnt == 1) {
                open = event[i].first;
            }
        } else {
            cnt--;
            if (cnt == 0) {
                vec.push_back(make_pair(open, vec[i].first));
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    return 0;
}

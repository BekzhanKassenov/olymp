/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

typedef map <int, pair <int, long long>, std::greater<int> > map_t;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    map_t mp;
    map_t temp;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            continue;
        }

        for (const auto& p : mp) {
            int ng = gcd(p.first, a[i]);
            if (ng == 1) {
                continue;
            }

            temp[ng].first += p.second.first;
            temp[ng].second += p.second.first + p.second.second;

            temp[p.first].first += p.second.first;
            temp[p.first].second += p.second.second;
        }

        temp[a[i]].first++;
        temp[a[i]].second++;

        mp.swap(temp);
        temp.clear();
    }
    
    return 0;
}

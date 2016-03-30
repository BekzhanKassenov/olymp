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

int n, m;
char buf[15];
int score, region;
vector <pair <int, string> > vec[10010];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("\n%s %d %d", buf, &region, &score);

        vec[region].emplace_back(score, string(buf));
    }

    for (int i = 1; i <= m; i++) {
        sort(all(vec[i]));

        int len = vec[i].size();
        if (len > 2 && vec[i][len - 2].first == vec[i][len - 3].first) {
            puts("?");
        } else {
            printf("%s %s\n", vec[i][len - 1].second.c_str(), vec[i][len - 2].second.c_str());
        }
    }

    return 0;
}

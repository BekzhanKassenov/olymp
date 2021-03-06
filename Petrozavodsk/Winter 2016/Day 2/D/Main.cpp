/****************************************
**          Solution by NU #2          **
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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];
vector <pair <char, int> > vec;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < n; i++) {
        if (vec.empty() || vec.back().first != s[i]) {
            vec.emplace_back(s[i], 1);
        } else {
            vec.back().second++;
        }
    }

    if (vec.size() % 2 == 1 || vec[0].first == '>') {
        printf("%d\n", n);
        return 0;
    }

    n -= min(vec[0].second, vec.back().second);
    printf("%d\n", n);
    
    return 0;
}

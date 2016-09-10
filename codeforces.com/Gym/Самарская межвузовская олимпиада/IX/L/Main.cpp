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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN], b[MAXN];

bool can_win(int a[], int b[]) {
    vector <pair <int, bool> > vec;
    for (int i = 0; i < n; i++) {
        vec.push_back({a[i], true});
    }

    for (int i = 0; i < n; i++) {
        vec.push_back({b[i], false});
    }

    sort(all(vec), [](const pair <int, int>& a, const pair <int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }

        return (int)a.second < (int)b.second;
    });

    /*
    for (auto p: vec) {
        fprintf(stderr, "{%d, %d} ", p.first, p.second);
    }
    fprintf(stderr, "\n");
    */

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (vec[i].second) {
            cnt++;
        } else {
            if (cnt > 0) {
                cnt--;
                ans++;
            }
        }
    }

    return 2 * ans > n;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    bool first = can_win(a, b);
    bool second = can_win(b, a);

    if (first && second) {
        puts("Both");
    } else if (first && !second) {
        puts("First");
    } else if (!first && second) {
        puts("Second");
    } else {
        puts("None");
    }
    
    return 0;
}

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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, p[MAXN];
bool used[MAXN];

int fixed() {
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            return i;
        }
    }

    return -1;
}

int len(int S) {
    int ans = 0;
    int cur = S;

    do {
        ans++;
        cur = p[cur];
    } while (cur != S);

    return ans;
}

int len2() {
    for (int i = 1; i <= n; i++) {
        if (p[p[i]] == i) {
            return i;
        }
    }

    return -1;
}

vector <pair <int, int> > ans;

void run(int a, int b) {
    while (!used[b]) {
        ans.push_back(make_pair(a, b));

        used[a] = true;
        used[b] = true;

        a = p[a];
        b = p[b];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int a;

    if ((a = fixed()) != -1) {
        used[a] = true;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                run(a, i);
            }
        }
    } else if ((a = len2()) != -1) {
        used[a] = true;
        run(a, p[a]);

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                if (len(i) % 2 == 0) {
                    run(a, i);
                } else {
                    puts("NO");
                    return 0;
                }
            }
        }
    } else {
        puts("NO");
        return 0;
    }

    puts("YES");
    for (auto& res: ans) {
        printf("%d %d\n", res.first, res.second);
    }

    return 0;
}

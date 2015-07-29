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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char name[MAXN][MAXN];
bool g[MAXN][MAXN];
int color[MAXN];

void set_less(char *s, char *t) {
    while (*s && *t) {
        if (*s != *t) {
            g[*t - 'a'][*s - 'a'] = true;
            break;
        }

        s++;
        t++;
    }

    if (*s && !*t) {
        puts("Impossible");
        exit(0);
    }
}

bool dfs(int v, vector <int>& order) {
    color[v] = 1;

    bool result = true;
    for (int i = 0; i < 26; i++) {
        if (!g[v][i])
            continue;

        if (color[i] == 1) {
            return false;
        }

        if (color[i] == 0) {
            result &= dfs(i, order);
        }
    }

    color[v] = 2;
    order.push_back(v);

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        gets(name[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set_less(name[i], name[j]);
        }
    }

    vector <int> order;
    bool result = true;

    for (int i = 0; i < 26; i++) {
        if (color[i] == 0) {
            result &= dfs(i, order);
        }
    }

    if (!result) {
        puts("Impossible");
    } else {
        //reverse(all(order));
        for (int i = 0; i < 26; i++) {
            putchar(order[i] + 'a');
        }
        puts("");
    }
    
    return 0;
}

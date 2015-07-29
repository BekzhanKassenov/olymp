/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "lots"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, mt[maxn], cnt[maxn];
char s[maxn][maxn], t[maxn][maxn];
bool used[maxn], can[maxn][maxn];

bool kuhn(int v) {
    if (used[v])
        return false;

    used[v] = true;

    for (int to = 0; to < n; to++) {
        if (!can[v][to])
            continue;

        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;    
        }
    }

    return false;
}

bool check(int x, int y) {
    bool res = true;
    
    for (int i = 0; i < m; i++) {
        res &= (s[x][i] == '?' || t[y][i] == '?' || s[x][i] == t[y][i]);
    } 

    return res;
}

bool check_t() {
    memset(cnt, 0, sizeof cnt);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[i] += t[i][j] == 'x';
        }
    }
/*
    for (int i = 0; i < n; i++)
        cerr << cnt[i] << ' ';
        cerr << endl;
                               */
    for (int i = 1; i < n; i++) {
        if (cnt[i] > cnt[i - 1])
            return false;
    }

    return true;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
        memset(mt, 255, sizeof mt);
        memset(used, false, sizeof used);

        for (int i = 0; i < n; i++)
            scanf("\n%s", s[i]);

        for (int i = 0; i < n; i++)
            scanf("\n%s", t[i]);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                can[i][j] = check(i, j);
    
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", can[i][j]);
            puts("");
        }*/

        
        bool res = true;

        for (int i = 0; i < n; i++) {
            memset(used, false, sizeof used);
            kuhn(i);
        }
        
        for (int i = 0; i < n; i++)
            res &= mt[i] != -1;

        if (!res || !check_t()) {
            puts("NO");
        } else {
            puts("YES");
            
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (mt[j] == i)
                        puts(t[j]);
        }
    }

    return 0;
}

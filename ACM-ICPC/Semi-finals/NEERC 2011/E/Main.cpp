/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "eve"

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

struct Person {
    char gender;
    int dna;
    bool alive;
};

Person p[MAXN];
int last;

int n, m, k;
vector <int> g[MAXN];
bool used[MAXN];

void dfs(int v, int d) {
    used[v] = true;
    p[v].dna = d;
    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to, d);
        }
    }
}

bool dfs1(int v) {
    used[v] = true;
    bool result = p[v].alive;

    for (int to: g[v]) {
        if (!used[to]) {
            result |= dfs1(to);
        }
    }

    return result;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("\n%c", &p[i].gender);
        p[i].dna = -1;
        p[i].alive = true;
    }

    last = n + 1;

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);

        if (num > 0) {
            int num1;
            char c;

            scanf("%d %c", &num1, &c);

            p[last].gender = c;
            p[last].dna = -1;
            p[last].alive = true;

            if (p[num].gender == 'F') {
                g[num].push_back(last);
                g[last].push_back(num);
            } else {
                g[num1].push_back(last);
                g[last].push_back(num1);
            }

            last++;

        } else {
            p[-num].alive = false;
        }
    }

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int id, dna;
        scanf("%d%d", &id, &dna);
        if (!used[id]) {
            dfs(id, dna);
        }
    }

    memset(used, false, sizeof used);
    int cnum = 0;
    for (int i = 1; i <= last; i++) {
        if (!used[i]) {
            cnum += dfs1(i);
        }
    }

    if (cnum <= 1) {
        puts("YES");
        return 0;
    }

    int prev = -1;
    bool found = false;
    for (int i = 1; i <= last; i++) {
        if (!p[i].alive) {
            continue;
        }

        if (p[i].dna == -1) {
            found = true;
            continue;
        }
        
        if (prev == -1) {
            prev = p[i].dna;
        } else {
            if (p[i].dna != prev) {
                puts("NO");
                return 0;
            }
        }
    }

    if (found) {
        puts("POSSIBLY");
        return 0;
    }

    puts("YES");

    return 0;
}

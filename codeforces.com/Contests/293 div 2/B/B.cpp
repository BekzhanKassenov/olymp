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

map <char, int> Map;

char toother(char c) {
    if (isupper(c)) {
        return tolower(c);
    }

    return toupper(c);
}

char s[MAXN], t[MAXN];
bool used[MAXN];
int n, m;
int ura, opa;

bool check(char c) {
    if (Map[c] > 0) {
        Map[c]--;

        return true;
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    gets(t);

    n = strlen(s);
    m = strlen(t);

    for (int i = 0; i < m; i++) {
        Map[t[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (check(s[i])) {
            ura++;
            used[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i] && check(toother(s[i]))) {
            used[i] = true;
            opa++;
        }
    }

    printf("%d %d\n", ura, opa);

    return 0;
}

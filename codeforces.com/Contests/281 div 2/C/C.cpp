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

int n, m;
int a[MAXN], b[MAXN];
long long suma[MAXN], sumb[MAXN];
long long ansa = -1, ansb = -1;

void update(int posa, int posb) {
    long long numa = 3ll * (n - posa) + 2ll * posa;
    long long numb = 3ll * (m - posb) + 2ll * posb;

    if ((ansa == -1 && ansb == -1) ||
        (numa - numb > ansa - ansb) ||
        (numa - numb == ansa - ansb && numa > ansa)) {
        
        ansa = numa;
        ansb = numb;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    a[n + 1] = INF;
    int posa = 0, posb = 0;
    update(posa, posb);

    while (posa <= n + 1) {
        posa++;

        while (posb < m && b[posb + 1] < a[posa]) {
            posb++;
            update(posa - 1, posb);
        }
    }

    printf("%I64d:%I64d\n", ansa, ansb);

    return 0;
}

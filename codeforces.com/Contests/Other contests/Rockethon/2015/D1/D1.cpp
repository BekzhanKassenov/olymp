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

int n, m;
int a, b;
char s[10];
vector <int> l[MAXN], r[MAXN];
vector <int> order;

void output(int left, int right) {
    if (left > right) {
        return;
    }

    int root = left;
    left++;

    int mid = -1;
    for (size_t i = 0; i < l[root].size(); i++) {
        mid = max(mid, l[root][i]);
    }

    if (mid == -1) {
        order.push_back(root);                                            
        output(left, right);                                              
        return;                                                           
    }                                                                     
                                                                          
    for (size_t i = 0; i < r[root].size(); i++) {                         
        if (r[root][i] <= mid || r[root][i] > right) {                                          
            puts("IMPOSSIBLE");
            exit(0);
        }
    }

    output(left, mid);
    order.push_back(root);
    output(mid + 1, right);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %s", &a, &b, s);
        if (b <= a) {
            puts("IMPOSSIBLE");
            return 0;
        }


        if (strcmp(s, "LEFT") == 0) {
            l[a].push_back(b);
        } else {
            r[a].push_back(b);
        }
    }

    output(1, n);

    for (size_t i = 0; i < order.size(); i++) {
        printf("%d ", order[i]);
    }

    return 0;
}

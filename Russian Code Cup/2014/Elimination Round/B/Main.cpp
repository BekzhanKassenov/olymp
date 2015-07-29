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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, n, a, b;
vector <int> chain[maxn], child[maxn];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T --> 0) {
        scanf("%d%d%d", &n, &a, &b);

        int chains = n - b;
        int leafs = n - a;

        if (chains > a || leafs < chains || a >= n || b >= n) {
            puts("IMPOSSIBLE");
        } else {
            for (int i = 0; i < chains; i++)
                chain[i].clear();

            int num = 1;

            for (int i = 0; i < chains; i++)
                chain[i].push_back(num++);
            
            int pos = 0;

            for (int i = 0; i < n - chains - leafs; i++) {
                child[chain[pos].back()].push_back(num);
                chain[pos++].push_back(num++);
                pos %= chains;
            }

            int last = chain[0].back();

            for (int i = 0; i < chains; i++) {
                child[chain[i].back()].push_back(num);
                chain[i].push_back(num++);
            }

            for (; num <= n; num++)
                child[last].push_back(num);

            for (int i = 1; i <= n; i++) {
                printf("%u ", child[i].size());

                for (size_t j = 0; j < child[i].size(); j++)
                    printf("%d ", child[i][j]);

                child[i].clear();
                puts("");
            }
        }             
    }
    
    return 0;
}

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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
int score[MAXN];
int mask[MAXN];
vector <int> v[1 << 11];
vector<int> z;
stringstream ss;

int read_trait() {
    int mask = 0;
    int k;

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        mask |= 1 << (x - 1);
    }

    return mask;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
        mask[i] = read_trait();
        z.push_back(score[i]);
        v[mask[i]].push_back(score[i]);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);

        int mask1 = read_trait();
        if (mask1 == 0) {
            cout << score[id] << " " << id << endl;
            cout << upper_bound(all(z), score[id]) - z.begin() << endl;
        }
        else {            
            mask1 |= mask[id];
            cout << upper_bound(all(v[mask1]), score[id])  - v[mask1].begin() << endl;        
        }
    }

    return 0;
}

/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define prev adasdasdsa
#define next qweqwewqewq
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 9;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 500 + 13;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int sum[2 * MAXN][2], prev[MAXN][MAXN], next[MAXN][MAXN];
vector <pair <int, char > > a;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x;

    cin >> n >> k;

    if ((n + k) & 1) { 
        cout << "0";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(MP(x, '('));
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(MP(x, ')'));
    }

    sort(all(a));

    if (a[0].second == '(') {
        sum[0][0] = 1;
    } else {
        sum[0][1] = 1;
    }

    for (size_t i = 1; i < a.size(); i++) {
        if (a[i].second == '(') {
            sum[i][0] = sum[i - 1][0] + 1;
            sum[i][1] = sum[i - 1][1];
        } else {
            sum[i][1] = sum[i - 1][1] + 1;
            sum[i][0] = sum[i - 1][0];                      
        }        
    }

    prev[0][0] = 1;

    for (int i = 0; i < 2 * n; i++) {
        for (int x = 0; x * 2 <= i; x++) {
            for (int y = 0; 2 * x + 2 * y <= i; y++) {
                int leftOpen = sum[i][0] - x - y;
                int leftClosed = sum[i][1] - x - y;

                if (leftOpen < 0 || leftClosed < 0) {
                    continue;
                }       

                if (a[i].second == '(') {
                    next[x][y + 1] += (1ll * prev[x][y] * leftClosed) % MOD;
                    next[x][y + 1] %= MOD;
                } else {
                    next[x + 1][y] += (1ll * prev[x][y] * leftOpen) % MOD;
                    next[x + 1][y] %= MOD;
                }

                next[x][y] += prev[x][y];
                next[x][y] %= MOD;
                
            }
        }
        memcpy(prev, next, sizeof(next));
        memset(next, 0, sizeof(next));
    }

    cout << prev[(n - k) / 2][(n + k) / 2] << endl;

    return 0;
}

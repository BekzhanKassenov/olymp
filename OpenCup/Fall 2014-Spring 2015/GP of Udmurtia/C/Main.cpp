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

template <typename T>
inline T sqr(T n) {
    return n * n;
}
int n, c[10];
vector<int> v[10];
vector<bool> vb[10];

double dp[10][14][1050];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> c[i] >> x;
        v[i].resize(x);
        vb[i].resize(x);
        for (int j = 0; j < x; j++) {
            cin >> v[i][j];
            char cc = cin.get();

            if (cin.peek() == '+') {
                cc = cin.get();
                vb[i][j] = true;
            }
        }

        dp[i][0][0] = 1.0;
    }

    int kk;
    cin >> kk;

    for (int i = 0; i < n; i++) {
        for (int step = 1; step <= c[i]; step++) {    
            for (size_t j = 0; j < v[i].size(); j++) {
                double sz = (v[i].size() + 0.0);
                int tt = v[i][j];
                for (int sum = 0; sum <= 1030; sum++) {
                    if (!vb[i][j])
                        dp[i][step][sum + tt] += dp[i][step-1][sum] / sz;    
                    else
                        dp[i][step][sum + tt] += dp[i][step][sum] / sz;    
                }
            }
        }
    }
    for (int k = 1; k <= kk; k++) {
        int index = -1;
        double prob = 0.0;
        for (int i = 0; i < n; i++) {
            double curp = 0.0;
            for (int j = k; j < 1050; j++) {
                curp += dp[i][c[i]][j];
            }
            if (prob < curp) {
                prob = curp;
                index = i;
            }
        }
        cout << index + 1 << endl;
    
    }
    return 0;
}

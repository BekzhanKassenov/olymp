/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "dice"

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

int m, n;
pair<int, int> v[1010];
vector<int> ans[1010];
double e;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        m += v[i].first;
    }

    sort(v, v + n);

    int cur = m;
    for (int j = 0; j < n; j++) {
        double sum = 0;
        for (int k = cur - v[j].first + 1; k <= cur; k++) {
            sum += (double)k;
            ans[v[j].second].push_back(k);
        }
        e += sum / (v[j].first + 0.0);
        cur -= v[j].first;
        
    }

    printf("%.5lf\n", e);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";

        }
        cout << endl;
    }
    return 0;
}

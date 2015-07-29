/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "freelance"

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
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, a[maxn], b[maxn], sum[2], sm;
vector <int> temp1;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", a + i, b + i);
        if (a[i] == 1) {
            temp1.push_back(b[i]);
        } else { 
            if (a[i] != 2) {
                cnt ^= (a[i] & 1);
            }

            sm += b[i];
        }
    }

    sort(all(temp1));
    reverse(all(temp1));

    for (size_t i = 0; i < temp1.size(); i++) {
        sum[i & 1] += temp1[i];
    }

    int cur = (temp1.size() & 1u);
    sum[(!cnt) ^ cur] += sm;

    cout << sum[0] << ' ' << sum[1] << endl;

    return 0;
}

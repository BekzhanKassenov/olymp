/****************************************
**          Solution by NU #2          **
****************************************/
#include <bits/stdc++.h>

using namespace std;
 
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "elves"
 
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
const int MAXN = 100010;
 
template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m;
pair<int, int> a[MAXN], b[MAXN];
vector<tuple<int, int, int>> ans;
 
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
   
    scanf("%d%d", &m, &n);
   
    for (int i = 1; i <= m; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
   
    for (int i = 1; i <= n; i++){
        scanf("%d", &b[i].first);
        b[i].second = i;
    }

    sort(a + 1, a + 1 + m);
    sort(b + 1, b + 1 + n);

    int other = n / 2 + 1;
    int deer = 0;
    for (int i = 1; i <= n; i++) {
        while (deer <= m && b[i].first >= a[deer].first) {
            deer++;
        }
        while (other <= n && a[deer].first >= b[other].first) {
            other++;
        }

        if (deer <= m && other <= n) {
            ans.emplace_back(a[deer].second, b[i].second, b[other].second);
            deer++;
            other++;
        }
    }   

    cout << ans.size() << endl;
    for (const auto tup : ans) {
        cout << get<0>(tup) << ' ' << get<1>(tup) << ' ' << get<2>(tup) << endl;
    }
   
    return 0;
}
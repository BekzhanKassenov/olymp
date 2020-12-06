/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
 
const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
 
template <typename T>
inline T sqr(T n) {
    return n * n;
}
 
int n;
long long v[MAXN], t[MAXN];
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
 
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
 
    multiset <long long> cur;
    long long pref = 0;
    for (int i = 1; i <= n; i++) {
        cur.insert(v[i] + pref);
        long long ans = 0;
        while (!cur.empty() && *cur.begin() <= pref + t[i]) {
            ans += *cur.begin() - pref;
            cur.erase(cur.begin());
        }
 
        ans += t[i] * cur.size();
        pref += t[i];
        cout << ans << ' ';
    }
    cout << endl;
 
    return 0;
}

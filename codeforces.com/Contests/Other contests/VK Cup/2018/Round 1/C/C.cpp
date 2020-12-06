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
const int MAXN = 300010;
const int L = 32;
 
template <typename T>
inline T sqr(T n) {
    return n * n;
}
 
int n;
long long a[MAXN], p[MAXN];
int l[L * MAXN], r[L * MAXN];
int cnt[L * MAXN];
int ROOT = 1;
int next_node = 2;
 
int charAt(long long num, int pos) {
    pos = L - 1 - pos;
    return (num >> pos) & 1;
}
 
int get_node(int idx) {
    if (idx == 0) {
        return next_node++;
    }
    return idx;
}
 
void add(long long num) {
    int cur = ROOT;
    for (int i = 0; i < L; i++) {
        int ch = charAt(num, i);
        if (ch == 0) {
            l[cur] = get_node(l[cur]);
            cur = l[cur];
        } else {
            r[cur] = get_node(r[cur]);
            cur = r[cur];
        }
        cnt[cur]++;
    }
}
 
long long get(long long num) {
    long long ans = 0;
    int cur = ROOT;
    for (int i = 0; i < L; i++) {
        ans <<= 1;
        int ch = charAt(num, i);
        if (ch == 0) {
            if (cnt[l[cur]] == 0) {
                ans |= 1;
                cur = r[cur];
            } else {
                cur = l[cur];
            }
        } else {
            if (cnt[r[cur]] == 0) {
                ans |= 1;
                cur = l[cur];
            } else {
                cur = r[cur];
            }
        }
        cnt[cur]--;
    }
    return ans;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        add(p[i]);
    }
 
    for (int i = 1; i <= n; i++) {
        cout << get(a[i]) << ' ';
    }
    cout << endl;
 
    return 0;
}

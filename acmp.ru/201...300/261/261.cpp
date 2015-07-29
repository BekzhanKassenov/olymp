#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1000010;
const ll INF = 2000000ll * 1000000 * 1000000;
 
int n, m, k, root = 1, last = 2, a[20];
int lc[maxn], rc[maxn], sib[maxn], size[maxn];
char buf[20], let[maxn];
 
int move_next(int current, int letter) {
    if (!lc[current]) {
        let[last] = letter;
        lc[current] = rc[current] = last++;
        return lc[current];
    }
 
    if (lc[current] == rc[current]) {
        if (let[lc[current]] == letter)
            return lc[current];
    }
 
    for (int i = lc[current]; i; i = sib[i]) {
        if (let[i] == letter)
            return i;
    }
 
    let[last] = letter;             
    sib[rc[current]] = last;
    rc[current] = last++;       
    return rc[current];         
}
 
void add(const char s[]) {
    int current = root;
 
    for (int i = 0; i < m; i++) {
        int child = move_next(current, s[i] - '0');
         
        size[current]++;
        current = child;
    }
 
    size[current]++;
}
 
ll solve(int current, int level = 0) {
    if (level == m + 1)
        return 0;
 
    int cnt = 0;
 
    for (int i = lc[current]; i; i = sib[i])
        cnt++;
 
    if (cnt < k)
        return size[current] * 1ll * a[level];
 
    ll ans = INF, sz = size[current];
 
    for (int i = lc[current]; i; i = sib[i]) {
        ll temp = (sz - size[i]) * a[level] + solve(i, level + 1);
 
        ans = min(ans, temp);
    }
 
    return ans;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d %d %d\n", &n, &m, &k);
 
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
 
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        add(buf);
    }
 
    printf("%I64d", solve(root));
 
    return 0;
}
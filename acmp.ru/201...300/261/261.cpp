#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1000010;
const ll INF = 2000000ll * 1000000 * 1000000;
 
int n, m, k, root = 1, last = 2, a[20];
int lc[maxn], sib[maxn], size[maxn];
char buf[20], let[maxn];

int read_next(int current, char letter) {
    if (!lc[current]) {
        return -1;
    }
    for (int i = lc[current]; i; i = sib[i]) {
        if (let[i] == letter)
            return i;
    }
    return -1;
} 

int move_next(int current, int letter) {
    int nxt = read_next(current, letter);
    if (nxt == -1) {
        let[last] = letter;
        sib[last] = lc[current];
        lc[current] = last;
        return last++;
    }
    return nxt;
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
 
    printf("%lld", solve(root));
 
    return 0;
}

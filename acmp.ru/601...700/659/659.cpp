#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 30;

vector <int> g[MAXN];
int n, m, k, x, y;
int mask, cnt;
int ans = -1, ansmask;

inline bool used(int msk, int num) {
    return (msk & (1 << num)) > 0;
}

inline void go(int pos, int cur = 0) {
    if (pos == n) {
        if (cnt == k) {
            if (ans < cur) {
                ans = cur;
                ansmask = mask;
            }
        }

        return;
    }

    int temp = cur;
    int temp1 = cur;

    for (size_t i = 0; i < g[pos].size(); i++) {
        if (g[pos][i] < pos) {
            if (used(mask, g[pos][i]))
                temp++;
            else
                temp1++;
        }
    }
    
    if (cnt < k) {
        mask |= (1 << pos);
        cnt++;
        
        go(pos + 1, temp);
        
        cnt--;
        mask ^= (1 << pos);
    }

    go(pos + 1, temp1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d\n", &x, &y);
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool flag = false;
    
    if (k > n - k) {
        k = n - k;
        flag = true;
    }

    go(0);

    if (flag)
        ansmask ^= (1 << n) - 1;

    for (int i = 0; i < n; i++) {
        if (used(ansmask, i))
            printf("%d ", i + 1);
    }

    return 0;
}

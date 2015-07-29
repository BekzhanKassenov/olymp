#include <iostream>
#include <cstdio>

const int maxn = 100010;
long long a[maxn];
int n, m, x, y, t, val;

void add(int l, int r, int val) {
    for (int i = l; i <= r; i++)
        a[i] += val;
}

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        
        if (t == 1) {
            scanf("%d%d%d", &x, &y, &val);
            
            add(--x, --y, val);
        } else {
            scanf("%d", &x);
            
            printf("%I64d\n", a[--x]);
        }
    }
}
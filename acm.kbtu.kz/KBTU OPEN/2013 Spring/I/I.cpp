#include <stdio.h>

const int maxn = 100010;

int a[maxn], t[maxn << 2], pos[maxn];

void push(int v, int l, int r) {
    if (l == r)
        a[l] += t[v];
    else {
        t[v << 1] += t[v];
        t[(v << 1) + 1] += t[v];
    }   

    t[v] = 0;
}

void query(int v, int l, int r, int z_l, int z_r, int val) {
    if (l > r || l > z_r || z_l > r)
        return;

    push(v, l, r);

    if (l >= z_l && r <= z_r) {
        t[v] += val;
    } else {
        int m = (l + r) >> 1;
        query( v << 1,      l,     m, z_l, z_r, val);
        query((v << 1) + 1, m + 1, r, z_l, z_r, val);
    }
}

int read(int v, int l, int r, int ind) {
    while (l < r) {
        push(v, l, r);

        int m = (l + r) >> 1;
        v <<= 1;
        
        if (ind >= l && ind <= m) 
            r = m;
        else {
            l = m + 1;
            v++;
        }
    }
    return a[l];
}

int main() {
    freopen("megasort.in", "r", stdin);
    freopen("megasort.out", "w", stdout);

    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pos[--x] = i;
        a[i] = i;
    }

    int l = 0, r = n - 1;

    while (l < r) {
        printf("%d\n", read(1, 0, n - 1, pos[l]) - l);
        query(1, 0, n - 1, 0, pos[l], 1);

        printf("%d\n", r - read(1, 0, n - 1, pos[r]));
        query(1, 0, n - 1, pos[r], n - 1, -1);
        
        l++, r--;
    }

    if (l == r)
        puts("0");

    return 0;   
}

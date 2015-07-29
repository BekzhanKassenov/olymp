#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000010;
const int MOD  = 1000 * 1000 * 1000;

struct Node {
    int x, y; 
    int l, r;
} mem[maxn];

void init(int pos, int xx) {
    mem[pos].x = xx;
    mem[pos].y = (rand() << 16) ^ rand();
    mem[pos].l = 0;
    mem[pos].r = 0;
}

void split(int v, int& l, int& r, int key) {
    if (!v) {
        l = r = 0;
    } else if (mem[v].x > key) {
        split(mem[v].l, l, mem[v].l, key);
        r = v;
    } else {
        split(mem[v].r, mem[v].r, r, key);
        l = v;
    }
}

void merge(int& v, int l, int r) {
    if (!l || !r)
        v = l ? l : r;

    if (mem[l].y > mem[r].y) {
        merge(mem[l].r, mem[l].r, r);
        v = l;
    } else {
        merge(mem[r].l, l, mem[r].l);
        v = r;
    }
}

void insert(int& v, int it) {
    if (!v) {
        v = it;
    } else if (mem[it].y > mem[v].y) {
        split(v, mem[it].l, mem[it].r, mem[it].x);
        v = it;
    } else {
        if (mem[v].x < mem[it].x)
            insert(mem[v].r, it);
        else
            insert(mem[v].l, it);
    }
}

void erase(int& v, int xx) {
    if (!v)
        return;

    if (mem[v].x == xx) {
        merge(v, mem[v].l, mem[v].r);
    } else {
        if (mem[v].x < xx)
            erase(mem[v].r, xx);
        else
            erase(mem[v].l, xx);
    }
}

int lower_bound(int v, int xx) {
    if (!v)
        return -1;

    if (mem[v].x == xx)
        return xx;

    if (mem[v].x < xx)
        return lower_bound(mem[v].r, xx);

    int temp = lower_bound(mem[v].l, xx);
    
    if (temp == -1)
        return mem[v].x;

    return temp;
}

int root, last = 1;
int n, x, prev_x;
char c;
bool flag;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &c, &x);

        if (c == '+') {
            if (flag) {
                x += prev_x;
                x %= MOD;
            }

            flag = false;
            init(last, x);
            insert(root, last++);
        } else {
            prev_x = lower_bound(root, x);
            flag = true;

            printf("%d\n", prev_x);
        }
    }

    return 0;
}
                    
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 300010;
const int MOD  = 1000 * 1000 * 1000;

int x[maxn], y[maxn], l[maxn], r[maxn];

void init(int pos, int xx) {
    x[pos] = xx;
    y[pos] = (rand() << 16) ^ rand();
    l[pos] = 0;
    r[pos] = 0;
}

void split(int v, int& ll, int& rr, int key) {
    if (!v) {
        ll = rr = 0;
    } else if (x[v] > key) {
        split(l[v], ll, l[v], key);
        rr = v;
    } else {
        split(r[v], r[v], rr, key);
        ll = v;
    }
}

void merge(int& v, int ll, int rr) {
    if (!ll || !rr)
        v = ll ? ll : rr;

    if (y[ll] > y[rr]) {
        merge(r[ll], r[ll], rr);
        v = ll;
    } else {
        merge(l[rr], ll, l[rr]);
        v = rr;
    }
}

void insert(int& v, int it) {
    if (!v) {
        v = it;
    } else if (y[it] > y[v]) {
        split(v, l[it], r[it], x[it]);
        v = it;
    } else {
        if (x[v] < x[it])
            insert(r[v], it);
        else
            insert(l[v], it);
    }
}

void erase(int& v, int xx) {
    if (!v)
        return;

    if (x[v] == xx) {
        merge(v, l[v], r[v]);
    } else {
        if (x[v] < xx)
            erase(r[v], xx);
        else
            erase(l[v], xx);
    }
}

int lower_bound(int v, int xx) {
    if (!v)
        return -1;

    if (x[v] == xx)
        return xx;

    if (x[v] < xx)
        return lower_bound(r[v], xx);

    int temp = lower_bound(l[v], xx);
    
    if (temp == -1)
        return x[v];

    return temp;
}

int root, last = 1;
int n, xx, prev_x;
char c;
bool flag;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &c, &xx);

        if (c == '+') {
            if (flag) {
                xx += prev_x;
                xx %= MOD;
            }

            flag = false;
            init(last, xx);
            insert(root, last++);
        } else {
            prev_x = lower_bound(root, xx);
            flag = true;

            printf("%d\n", prev_x);
        }
    }

    return 0;
}
                    
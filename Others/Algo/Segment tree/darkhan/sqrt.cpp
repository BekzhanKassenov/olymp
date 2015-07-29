#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>

typedef long long i64;

using namespace std;

struct Block {
    
    int size, type;
    int Z[500];
    i64 sum, value;

    Block() {
        sum = value = type = 0;
        size = 500;
        memset(Z, 0, sizeof(Z));
    }

    void updateType(int v) {
        if (v == 2) {
            if (type == 0) type = 2;
        } else if (v == 1) {
            type = 1;
        }
    }

    void update() {
        if (type == 1) {
            sum = value * size;

            for (int i = 0; i < size; i++)
                Z[i] = value;
        } else if (type == 2) {
            sum += value * size;

            for (int i = 0; i < size; i++)
                Z[i] += value;
        }

        value = type = 0;
    }

    void set(int l, int r, int x) {
        for (int j = l; j <= r; j++) {
            sum += -Z[j] + x;
            Z[j] = x;
        }
    }

    void add(int l, int r, int x) {
        for (int j = l; j <= r; j++) {
            sum += x;
            Z[j] += x;
        }
    }

    i64 getSum(int l, int r) {
        i64 res = 0;
        for (int j = l; j <= r; j++) res += Z[j];
        return res;
    }

    i64 getSum() {
        if (type == 1) {
            return 500 * value;
        }
        return sum + value * 500;
    }
};

struct Tree {

    Block Z[500];

    void add(int l, int r, int x) {
        int i = l / 500;
        int j = r / 500;
        Z[i].update();
        Z[j].update();
        if (i == j) {
            Z[i].add(l % 500, r % 500, x);
        } else {
            for (int b = i + 1; b < j; b++) {
                Z[b].updateType(2);
                Z[b].value += x;
            }
            Z[i].add(l % 500, 499, x);
            Z[j].add(0, r % 500, x);
        }
    }

    void set(int l, int r, int x) {
        int i = l / 500;
        int j = r / 500;
        Z[i].update();
        Z[j].update();
        if (i == j) {
            Z[i].set(l % 500, r % 500, x);
        } else {
            for (int b = i + 1; b < j; b++) {
                Z[b].updateType(1);
                Z[b].value = x;
            }
            Z[i].set(l % 500, 499, x);
            Z[j].set(0, r % 500, x);
        }
    }

    i64 get(int l, int r) {
        int i = l / 500;
        int j = r / 500;
        Z[i].update();
        Z[j].update();
        if (i == j) {
            return Z[i].getSum(l % 500, r % 500);
        } 
        i64 res = 0;
        for (int b = i + 1; b < j; b++) {
            res += Z[b].getSum();
        }
        res += Z[i].getSum(l % 500, 499);
        res += Z[j].getSum(0, r % 500);
        return res;
    }

};

Tree tree;

int main() {
    freopen("input", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        char s[10];
        scanf("%s", s);
        int l, r, x;
        if (strcmp(s, "ADD") == 0) {
            scanf("%d%d%d", &l, &r, &x);
            tree.add(l, r, x);
        } else if (strcmp(s, "SET") == 0) {
            scanf("%d%d%d", &l, &r, &x);
            tree.set(l, r, x);
        } else if (strcmp(s, "GET") == 0) {
            scanf("%d%d", &l, &r);
            printf("%I64d\n", tree.get(l, r));
        } else {
            assert(0);
        }
//      tree.print();
    }

    return 0;
}
                    
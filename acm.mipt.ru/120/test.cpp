#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int MAXN = 2 * 100010;

enum QTYPE {
    ADD,
    COUNT,
    DELETE
};

struct Query {
    QTYPE type;

    int x, y, xx, yy;

    bool read() {
        static char buf[10];

        if (scanf("%s", buf) != 1) {
            return false;
        }

        if (strcmp(buf, "ADD") == 0) {
            type = ADD;
            scanf("%d %d\n", &x, &y);
        } else if (strcmp(buf, "COUNT") == 0) {
            type = COUNT;
            scanf("%d %d %d %d\n", &x, &y, &xx, &yy);
        } else if (strcmp(buf, "DELETE") == 0) {
            type = DELETE;
            scanf("%d %d\n", &x, &y);
        }
         
        return true;
    }
};

Query q[MAXN];
int n;

class Fenwick {
    int *key;
    int *val;
    int size;

    void update(int pos, int delta) {
        for (int i = pos; i < size; i |= i + 1) {
            val[i] += delta;
        }
    }

    int sum(int pos) {
        int result = 0;
        for (int i = min(pos, size - 1); i >= 0; i = (i & (i + 1)) - 1) {
            result += val[i];
        }

        return result;
    }


public:
    Fenwick() { }

    void init(const vector <int>& vec) {
        size = vec.size();
        key = new int[size];

        for (size_t i = 0; i < vec.size(); i++) {
            key[i] = vec[i];
        }
        
        sort(key, key + size);
        size = unique(key, key + size) - key;
        val = new int[size];
        memset(val, 0, sizeof(val[0]) * size);
    }

    void init(const Fenwick& lhs, const Fenwick& rhs) {
        size = lhs.size + rhs.size;
        key = new int[size];

        merge(lhs.key, lhs.key + lhs.size, 
              rhs.key, rhs.key + rhs.size, 
              key);

        size = unique(key, key + size) - key;
        val = new int[size];
        memset(val, 0, sizeof(val[0]) * size);
    }

    bool contains(int num) {
        int numPos = lower_bound(key, key + size, num) - key;

        if (numPos == size || key[numPos] != num) {
            return false;
        }

        return sum(numPos) - sum(numPos - 1) > 0;
    }

    void add(int num) {
        int numPos = lower_bound(key, key + size, num) - key;

        assert(numPos != size && key[numPos] == num);

        update(numPos, 1);
    }

    void remove(int num) {
        int numPos = lower_bound(key, key + size, num) - key;

        assert(numPos != size && key[numPos] == num);

        update(numPos, -1);
    }

    int count(int l, int r) {

        int lPos = lower_bound(key, key + size, l) - key;
        int rPos = upper_bound(key, key + size, r) - key - 1;

        if (lPos == size && rPos == size && lPos > rPos) {
            return 0;
        }

        return sum(rPos) - sum(lPos - 1);
    }
};

/*================= Segment Tree ==================*/

vector <int> a[2 * MAXN];
Fenwick t[8 * MAXN];

void build(int v, int l, int r) {
    if (l == r) {
        t[v].init(a[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    t[v].init(t[2 * v], t[2 * v + 1]);
}

bool add(int v, int l, int r, int x, int y) {
    if (l == r) {
        if (t[v].contains(y)) {
            return false;
        }

        t[v].add(y);
        return true;
    }

    int mid = (l + r) / 2;
    bool result = (x <= mid) ? add(2 * v, l, mid, x, y)
                             : add(2 * v + 1, mid + 1, r, x, y);

    if (result) {
        t[v].add(y);
    }

    return result;
}

bool remove(int v, int l, int r, int x, int y) {
    if (l == r) {
        if (t[v].contains(y)) {
            t[v].remove(y);
            return true;
        }

        return false;
    }

    int mid = (l + r) / 2;
    bool result = (x <= mid) ? remove(2 * v, l, mid, x, y)
                             : remove(2 * v + 1, mid + 1, r, x, y);

    if (result) {
        t[v].remove(y);
    }

    return result;
}


int count(int v, int l, int r, int x, int xx, int y, int yy) {
    if (x > r || l > xx) {
        return 0;
    }

    if (x <= l && r <= xx) {
        return t[v].count(y, yy);
    }

    int mid = (l + r) / 2;

    return count(2 * v, l, mid, x, xx, y, yy) + 
           count(2 * v + 1, mid + 1, r, x, xx, y, yy);
}

/*================= End of Segment Tree ==================*/

vector <int> compr;
int getX(int x) {
    return lower_bound(all(compr), x) - compr.begin();
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (q[n].read()) {
        compr.push_back(q[n].x);

        if (q[n].type == COUNT) {
            compr.push_back(q[n].xx);
        }

        n++;
    }

    if (n == 0) {
        return 0;
    }

    sort(all(compr));
    compr.resize(unique(all(compr)) - compr.begin());
    int k = compr.size();

    for (int i = 0; i < n; i++) {
        if (q[i].type != COUNT) {
            int pos = lower_bound(all(compr), q[i].x) - compr.begin();
            a[pos].push_back(q[i].y);
        }
    }

    build(1, 0, k - 1);

    for (int i = 0; i < n; i++) {
        switch (q[i].type) {
            case ADD:
                if (add(1, 0, k - 1, getX(q[i].x), q[i].y)) {
                    puts("ADDED");
                } else {
                    puts("ALREADY EXISTS");
                }

                break;

            case DELETE:
                if (remove(1, 0, k - 1, getX(q[i].x), q[i].y)) {
                    puts("DELETED");
                } else {
                    puts("NOT FOUND");
                }

                break;

            case COUNT:
                printf("%d\n", count(1, 0, k - 1, getX(q[i].x), getX(q[i].xx), q[i].y, q[i].yy));
                break;
        }
    }
    
    return 0;
}
                                     
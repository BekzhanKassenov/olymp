#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

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
set <pair <int, int> > Set;

int count(const Query& q) {
    int ans = 0;
    for (auto it: Set) {
        if (q.x <= it.first && it.first <= q.xx &&
            q.y <= it.second && it.second <= q.yy) {

            ans++;
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (q[n].read()) {
        n++;
    }

    for (int i = 0; i < n; i++) {
        if (q[i].type == ADD) {
            if (Set.count(make_pair(q[i].x, q[i].y))) {
                puts("ALREADY EXISTS");
            } else {
                Set.insert(make_pair(q[i].x, q[i].y));
                puts("ADDED");
            }
        } else if (q[i].type == COUNT) {
            printf("%d\n", count(q[i]));
        } else {
            if (Set.count(make_pair(q[i].x, q[i].y))) {
                Set.erase(make_pair(q[i].x, q[i].y));
                puts("DELETED");
            } else {
                puts("NOT FOUND");
            }
        }
    }
    
    return 0;
}

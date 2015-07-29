#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int maxn = 210;

struct rect {
    int x, y, _x, _y;

    bool read() {
        scanf("%d%d%d%d", &x, &y, &_x, &_y);

        if (x == _x || y == _y)
            return false;

        if (x > _x)
            swap(x, _x);

        if (y > _y)
            swap(y, _y);

        return true;
    }
};

struct triple {
    int y, _y;
    bool open;

    triple() { }

    triple(int y, int _y, bool open) : y(y), _y(_y), open(open) { }
};

int n, last;
rect temp;
vector <triple> mem[20010], *a;

int get(const multiset <pair <int, int> >& st) {
    if (st.empty())
        return 0;

    int res = 0;
    int bal = 0;

    for (multiset <pair <int, int> > :: const_iterator it = st.begin(); it != st.end(); it++) {
        multiset <pair <int, int> > :: const_iterator prev = it;
        prev--;

        if (bal)
            res += it -> first - prev -> first;

        if (it -> second == false)
            bal++;
        else
            bal--;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    a = mem + 10010;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (temp.read()) {
            a[temp.x ].push_back(triple(temp.y, temp._y, true ));
            a[temp._x].push_back(triple(temp.y, temp._y, false));
        }
    }

    multiset <pair <int, int> > Set;
    int ans = 0;

    a = mem;

    for (int i = 0; i < 20010; i++) {
        for (size_t j = 0; j < a[i].size(); j++) {
            if (a[i][j].open) {
                Set.insert(make_pair(a[i][j].y, false));
                Set.insert(make_pair(a[i][j]._y, true));
            } else {
                Set.erase(Set.find(make_pair(a[i][j].y, false)));
                Set.erase(Set.find(make_pair(a[i][j]._y, true)));
            }
        }
        
        ans += get(Set);
    }

    printf("%d\n", ans);

    return 0;
}

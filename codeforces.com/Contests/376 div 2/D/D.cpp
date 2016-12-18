/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum TYPE {
    OPEN,
    CLOSE
};

int n, c;
vector <int> vec[MAXN];

pair <int, int> get_range(const vector <int>& vec) {
    int pos = min_element(all(vec)) - vec.begin();

    bool allequal = true;
    int prev = -1;
    for (int i = 0; i < (int)vec.size(); i++) {
        int idx = (pos + i) % vec.size();
        if (vec[idx] < prev) {
            return make_pair(-1, -1);
        }

        prev = vec[idx];
        if (vec[idx] != vec[pos]) {
            allequal = false;
        }
    }
    if (allequal) {
        return make_pair(0, c - 1);
    }

    int beg = 0;

    if (pos == 0) {
        beg = 0;
        end = c - vec.back();
    }

    if (pos != 0) {
        beg = c - vec[0] + 1;
    }

    int maxval = vec.back() + beg;
    int end = beg + c - maxval;

    if (pos == 0) {
        end = c - vec.back();
    }

    return make_pair(beg, end);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &c);

    int maxsize = 0;
    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);
        for (int j = 0; j < size; j++) {
            int x;
            scanf("%d", &x);
            vec[j].push_back(x);
        }

        maxsize = max(maxsize, size);
    }

    /*
    for (int i = 0; i < maxsize; i++) {
        for (int j = 0; j < (int)vec[i].size(); j++) {
            cerr << vec[i][j] <<' ' ;
        }
        cerr << endl;
    }
    cerr << endl;
    */

    vector <pair <int, TYPE> > events;

    for (int i = 0; i < maxsize; i++) {
        pair <int, int> range = get_range(vec[i]);

        cerr << range.first << ' ' << range.second << endl;

        if (range.first == -1 && range.second == -1) {
            puts("-1");
            return 0;
        }
        events.emplace_back(range.first, OPEN);
        events.emplace_back(range.second, CLOSE);
    }

    sort(all(events));

    int bal = 0;
    for (auto p: events) {
        if (p.second == OPEN) {
            bal++;
        } else {
            bal--;
        }

        if (bal == maxsize) {
            printf("%d\n", p.first);
            return 0;
        }
    }

    puts("-1");

    return 0;
}

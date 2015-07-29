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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ostream& operator << (ostream& out, const pair <int, int>& p) {
    out << '{' << p.first << ", " << p.second << '}';
    return out;
}

struct CompareLen {
    bool operator () (const pair <int, int>& a, const pair <int, int>& b) const {
        if (a.second - a.first != b.second - b.first) {
            return a.second - a.first > b.second - b.first;
        }

        return a.first < b.first;
    }
};

struct Compare {
    bool operator () (const pair <int, int>& a, const pair <int, int>& b) const {
        return a.first < b.first;
    }
};

int w, h, n, x;
char c;
set <pair <int, int>, Compare> row, col;
set <pair <int, int>, CompareLen> row_len, col_len;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d\n", &w, &h, &n);

    row.insert(make_pair(0, h));
    col.insert(make_pair(0, w));

    row_len.insert(make_pair(0, h));
    col_len.insert(make_pair(0, w));

    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &c, &x);

        if (c == 'H') {
            pair <int, int> range = *(--row.upper_bound(make_pair(x, 0)));
            
            if (x != range.first && x != range.second) {
                row.erase(range);
                row_len.erase(range);
                
                row.insert(make_pair(range.first, x));
                row.insert(make_pair(x, range.second));

                row_len.insert(make_pair(range.first, x));
                row_len.insert(make_pair(x, range.second));
            }

        } else {
            pair <int, int> range = *(--col.upper_bound(make_pair(x, 0)));
            
            if (x != range.first && x != range.second) {
                col.erase(range);
                col_len.erase(range);
                
                col.insert(make_pair(range.first, x));
                col.insert(make_pair(x, range.second));

                col_len.insert(make_pair(range.first, x));
                col_len.insert(make_pair(x, range.second));
            }
        }

        pair <int, int> a = *row_len.begin();
        pair <int, int> b = *col_len.begin();

        printf("%I64d\n", 1ll * (a.second - a.first) * (b.second - b.first));

    }
    
    return 0;
}

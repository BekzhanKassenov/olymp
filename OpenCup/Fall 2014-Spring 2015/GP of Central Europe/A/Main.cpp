/****************************************
**          Solution by NU #2          **
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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Meeting {
    int start, end, num;

    Meeting() { }

    Meeting(int start, int end, int num) : start(start), end(end), num(num) { }

    bool operator < (const Meeting& m) const {
        if (start != m.start)
            return start < m.start;

        return end < m.end;
    }
};

int n, m;
vector <Meeting> a[21];
int start, end, day;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &start, &end, &day);
        a[day - 1].push_back(Meeting(start, end, i + 1));
    }

    for (int i = 0; i < m; i++) {
        sort(all(a[i]));

        bool found = false;

        for (size_t j = 0; j < a[i].size() && !found; j++) {
            int nxt = a[i][j].end + 1;

            vector <Meeting> :: iterator pos = lower_bound(all(a[i]), Meeting(nxt, 0, 0));

            if (pos != a[i].end()) {
                printf("TAK %d %d\n", a[i][j].num, pos->num);
                found = true;
            }
        }

        if (!found)
            puts("NIE");
    }

    return 0;
}

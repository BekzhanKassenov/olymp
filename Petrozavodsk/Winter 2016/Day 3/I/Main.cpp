/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Event {
    int r1, r2;
    long long t;

    Event(int r1, int r2, long long t) : r1(r1), r2(r2), t(t) { }

    bool operator < (const Event& event) const {
        if (t != event.t) {
            return t > event.t;
        }

        if (r1 != event.r1) {
            return r1 < event.r1;
        }

        return r2 < event.r2;
    }
};

int n;
long long x[MAXN], y[MAXN];
long long ansX[MAXN], ansY[MAXN];
long long T;
char dir[MAXN];
bool touched[MAXN];

struct CompareX {
    bool operator () (int a, int b) const {
        return x[a] < x[b];
    }
};

struct CompareY {
    bool operator () (int a, int b) const {
        return y[a] < y[b];
    }
};

map <int, multiset <int, CompareX> > mapY;
map <int, multiset <int, CompareY> > mapX;
priority_queue <Event> events;

template <typename T>
typename multiset <int, T>::iterator findNext(const multiset <int, T>& Set, int num) {
    return Set.lower_bound(num);
}

template <typename T>
typename multiset <int, T>::iterator findPrev(const multiset <int, T>& Set, int num) {
    auto iter = Set.lower_bound(num);
    if (iter == Set.begin()) {
        return Set.end();
    }

    iter--;
    return iter;
}

void addCollision(int num, long long t) {
    int nxt = -1;
    int dx = 0, dy = 0;

    multiset <int, CompareX>::iterator it1;
    multiset <int, CompareY>::iterator it2;

    switch (dir[num]) {
        case 'L':
            dx = -1;
            it2 = findPrev(mapY[y[num]], num);
            if (it2 != mapY[y[num]].end()) {
                nxt = *it2;
            }

            break;

        case 'R':
            dx = 1;
            it2 = findNext(mapY[y[num]], num);
            if (it2 != mapY[y[num]].end()) {
                nxt = *it2;
            }

            break;
        
        case 'U':
            dy = 1;
            it1 = findNext(mapX[x[num]],num);
            if (it1 != mapX[x[num]].end()) {
                nxt = *it1;
            }

            break;

        case 'D':
            dy = -1;
            it1 = findPrev(mapX[x[num]], num);
            if (it1 != mapX[x[num]].end()) {
                nxt = *it1;
            }
            
            break;

        default:
            break;
    }

    if (nxt != -1) {
        long long diff = max(abs(x[num] - x[nxt]), abs(y[num] - y[nxt]));
        long long when = min(diff + t, T);
        x[num] += dx * diff;
        y[num] += dy * diff;
        events.emplace(num, nxt, when);
    }
}

void touch(int num, long long t) {
    if (touched[num]) {
        return;
    }

    touched[num] = true;

    int dx = 0, dy = 0;

    switch (dir[num]) {
        case 'L':
            dx = -1;
            break;

        case 'R':
            dx = 1;
            break;

        case 'U':
            dy = 1;
            break;

        case 'D':
            dy = -1;
            break;

        default:
            break;
    }

    ansX[num] += dx * (T - t);
    ansY[num] += dy * (T - t);

    mapY[y[num]].erase(mapY[y[num]].find(num));
    mapX[x[num]].erase(mapX[x[num]].find(num));

    addCollision(num, t);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
                                                                            
    scanf("%d" I64, &n, &T);
    for (int i = 1; i <= n; i++) {
        scanf(I64 I64 "\n%c", &x[i], &y[i], &dir[i]);
        ansX[i] = x[i];
        ansY[i] = y[i];

        mapY[y[i]].insert(i);
        mapX[x[i]].insert(i);
    }

    touch(1, 0);

    while (!events.empty()) {
        Event event = events.top();
        events.pop();

        touch(event.r2, event.t);
        addCollision(event.r1, event.t);
    }

    for (int i = 1; i <= n; i++) {
        printf(I64 " " I64 "\n", ansX[i], ansY[i]);
    }
    
    return 0;
}
            
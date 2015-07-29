/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define x first
#define y second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(q) (q).begin(), (q).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
    return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, t, t_x, t_y, tmp_x, tmp_y, tx, ty, a[510][510];
char c;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool have_around(int x, int y, int val) {
    for (int i = 0; i < 4; i++) {
        tx = x + dx[i];
        ty = y + dy[i];

        if (ok(tx, ty) && a[tx][ty] == val) 
            return true;
    }

    return false;
}

int ans;

stringstream ss;

void make(char c, int x, int y) { 
    ss << c << ' ' << x << ' ' << y << endl;
    ans++;
}

struct que {
    int q[500 * 500 + 100];

    int head, tail;

    que() : head(0), tail(0) {}

    bool empty() {
        return (head >= tail);
    }

    void push(int n) {
        q[tail++] = n;
    }

    int front() {
        return q[head];
    }

    void pop() {
        head++;
    }

    void clear() {
        head = 0;
        tail = 0;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        getchar();

        for (int j = 0; j < m; j++) {
            c = getchar();

            if (c == '#')
                a[i][j] = -1;
        }
    }

    que q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!a[i][j]) {
                q.push(i * m + j);
                a[i][j] = 1;
                make('B', i + 1, j + 1);

                while (!q.empty()) {
                    t = q.front();
                    t_x = t / m;
                    t_y = t % m;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        tmp_x = t_x + dx[k];
                        tmp_y = t_y + dy[k];

                        if (ok(tmp_x, tmp_y) && a[tmp_x][tmp_y] == 0) {
                            a[tmp_x][tmp_y] = 1;
                            q.push(tmp_x * m + tmp_y);
                            make('B', tmp_x + 1, tmp_y + 1);
                        }
                    }
                }

                //for (int k = q.tail - 1; k > 0; k--)
                //  cout << q.q[k] / m << ' ' << q.q[k] % m << "     ";

                //cout << endl; 
                
                for (int k = q.tail - 1; k > 0; k--) {
                    t = q.q[k];

                    t_x = t / m;
                    t_y = t % m;

                    if (have_around(t_x, t_y, 1)) {
                        make('D', t_x + 1, t_y + 1);
                        make('R', t_x + 1, t_y + 1);
                        a[t_x][t_y] = 2;
                    }
                }

                q.clear();
            }
        }
    }

    printf("%d\n", ans);

    cout << ss.str();

    return 0;
}
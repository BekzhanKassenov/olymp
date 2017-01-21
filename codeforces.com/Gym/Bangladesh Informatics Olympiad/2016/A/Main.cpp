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
const int MAXN = 800100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
int t[MAXN];
int id[MAXN];
int head, tail;
map <int, int> pos;

void add(int pos, int delta) {
    for (int i = pos; i < MAXN; i |= i + 1) {
        t[i] += delta;
    }
}

int sum(int pos) {
    int ans = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        ans += t[i];
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &T);

    for (int _case = 1; _case <= T; _case++) {
        printf("Case %d:\n", _case);
        scanf("%d\n", &n);
        head = MAXN / 2;
        tail = MAXN / 2 + 1;

        while (n--) {
            int type;
            scanf("%d ", &type);

            char x;
            int y;
            switch (type) {
                case 1:
                    scanf("%c %d\n", &x, &y);
                    if (x == 'B') {
                        add(tail, 1);
                        pos[y] = tail;
                        id[tail] = y;
                        tail++;
                    } else {
                        add(head, 1);
                        pos[y] = head;
                        id[head] = y;
                        head--;
                    }
                    break;

                case 2:
                    scanf("%c\n", &x);
                    if (x == 'B') {
                        tail--;
                        add(tail, -1);
                        id[tail] = 0;
                    } else {
                        head++;
                        add(head, -1);
                        id[head] = 0;
                    }
                    break;

                case 3:
                    scanf("%c %d\n", &x, &y);
                    if (x == 'P') {
                        printf("%d\n", sum(pos[y]));
                    } else {
                        int l = 0, r = MAXN - 1;
                        int ans = -1;
                        while (l <= r) {
                            int mid = (l + r) / 2;
                            int s = sum(mid);
                            if (s == y) {
                                ans = mid;
                            }

                            if (s < y) {
                                l = mid + 1;
                            } else {
                                r = mid - 1;
                            }
                        }

                        printf("%d\n", id[ans]);
                    }
                    break;

                default:
                    assert(false);
            }
        }

        for (int i = head; i <= tail; i++) {
            if (id[i] != 0) {
                add(i, -1);
                id[i] = 0;
            }
        }

        pos.clear();
    }
    
    return 0;
}

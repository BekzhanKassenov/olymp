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
typedef pair <queue <int>, queue <int> > State;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

set <State> used;
int n, k, x, cnt;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    queue <int> q1, q2;

    scanf("%d", &n);

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        q1.push(x);
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        q2.push(x);
    }

    used.insert(State(q1, q2));

    while (true) {
        cnt++;
        int card1 = q1.front();
        int card2 = q2.front();

        q1.pop();
        q2.pop();

        if (card1 > card2) {
            q1.push(card2);
            q1.push(card1);
        } else {
            q2.push(card1);
            q2.push(card2);
        }

        if (q1.empty()) {
            printf("%d 2\n", cnt);
            return 0;
        } else if (q2.empty()) {
            printf("%d 1\n", cnt);
            return 0;
        }

        if (used.count(State(q1, q2))) {
            puts("-1");
            return 0;
        }

        used.insert(State(q1, q2));
    }
    
    return 0;
}

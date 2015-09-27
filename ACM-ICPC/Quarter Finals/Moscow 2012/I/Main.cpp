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

int Wr, Wt, Hr, Ht;

int solve_bot(int W) {
    int t_width = (Ht / (Hr % Ht)) * Wt;

    return (W + t_width - 1) / t_width;
}

int solve_right(int H) {
    int t_height = (Wt / (Wr % Wt)) * Ht;

    return (H + t_height - 1) / t_height;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d %d", &Wr, &Hr);

    scanf("%d %d", &Wt, &Ht);

    int ans = (Wr / Wt) * (Hr / Ht);
    if (Wr % Wt == 0 && Hr % Ht == 0) {
        //
    } else if (Wr % Wt == 0) {
        ans += solve_bot(Wr);
    } else if (Hr % Ht == 0) {
        ans += solve_right(Hr);
    } else {
        ans += min(solve_bot(Wr) + solve_right(Hr - Hr % Ht),
                   solve_bot(Wr - Wr % Wt) + solve_right(Hr));
    }

    printf("%d\n", ans);

    return 0;
}

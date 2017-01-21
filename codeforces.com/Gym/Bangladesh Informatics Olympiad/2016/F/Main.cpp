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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    for (int _case = 1; _case <= T; _case++) {
        int n, A;
        scanf("%d%d", &n, &A);

        u32string s;
        set <int> letters;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            s.push_back(x);
            letters.insert(x);
        }

        set <u32string> Set;
        for (int i = 0; i < n; i++) {
            Set.insert(s.substr(0, i) + s.substr(i + 1));
        }

        int ans = Set.size();
        ans = (1ll * ans * n) % MOD;
        ans = (1ll * ans * (A - letters.size())) % MOD;

        set <u32string> setans;
        for (const auto& str : Set) {
            for (int c : letters) {
                for (int pos = 0; pos < n; pos++) {
                    auto temp(str);
                    temp.insert(pos, 1, c);
                    setans.emplace(temp);
                }
            }
        }

        ans += setans.size();
        ans %= MOD;

        printf("%d\n", ans);
    }
    
    return 0;
}

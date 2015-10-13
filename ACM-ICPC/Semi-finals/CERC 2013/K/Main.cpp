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

int T, n;
char s[3];
char result[100][100];
bool can[26][26];
vector <char> ans, cur;

int dfs(int v, int depth = 0) {
    cur.push_back(v + 'a');

    if (ans.size() < cur.size()) {
        ans = cur;
    }

    if (depth == 39) {
        cur.pop_back();
        return 39;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (can[v][i]) {
            ans = max(ans, dfs(i, depth + 1));

            if (ans == 39) {
                break;
            }
        }
    }

    cur.pop_back();

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        ans.clear();
        memset(can, true, sizeof can);

        scanf("%d\n", &n);

        for (int i = 0; i < n; i++) {
            gets(s);
            can[s[0] - 'a'][s[1] - 'a'] = false;
        }

        for (int i = 0; i < 26; i++) {
            dfs(i);
        }

        if (ans.size() % 2 == 0) {
            ans.pop_back();
        }

        int size = ans.size() / 2 + 1;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = ans[i + j];
            }

            result[i][size] = '\0';
        }

        for (int i = 0; i < size; i++) {
            puts(result[i]);
        }
    }
    
    return 0;
}

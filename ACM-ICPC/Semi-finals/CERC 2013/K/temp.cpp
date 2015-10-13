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
    
    for (char c = 'a'; c <= 'z'; c++) {
        for (char q = 'a'; q <= 'z'; q++) {
            cout << c << q << endl;
        }
    }
    
    return 0;
}

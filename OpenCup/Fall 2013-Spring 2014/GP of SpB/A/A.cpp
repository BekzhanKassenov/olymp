/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal
#define File "bracket-expression"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int next[100];

ll solve(int l, int r) {
    if (l > r)
        return 1;

    if (next[l] == r)
        return solve(l + 1, r - 1) + 1;

    ll cur = 1;

    while (l != r && next[l] != 0) {
        cur *= solve(l, next[l]);
        l = next[l] + 1;
    }

    return cur;
}
 
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    string s;

    getline(cin, s);
    if (s.empty()) {
        cout << 1;
        return 0;
    }

    stack <int> st;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(')
            st.push(i);
        else {
            next[st.top()] = i;
            st.pop();
        }   
    }

    cout << solve(0, (int)s.size() - 1);


    return 0;
}

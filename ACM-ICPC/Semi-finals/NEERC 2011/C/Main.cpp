/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "caption"

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

int m, n, k, smin, smax;
int letters[27][31];
int grid[2010];
int dp[2010][31];
int par[2010][31];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> m >> n >> k >> smin >> smax;

    string buf;
    getline(cin, buf);
    getline(cin, buf);

    int letnum = (buf.size() + 1) / (k + 3);

    vector <int> lets(letnum);
    for (int i = 0; i < letnum; i++) {
        lets[i] = buf[(k + 3) * i] - 'A';
    }
    
    auto parserow = [&](int rownum) {
        for (int i = 0; i < letnum; i++) {
            for (int j = 0; j < k; j++) {
                int isOn = buf[(i * (k + 3)) + 2 + j] == '*';
                letters[lets[i]][j] |= isOn << rownum;
            }
        }
    };

    auto conv = [](char c) {
        if (c == ' ') {
            return 26;
        }
        return c - 'A';
    };

    parserow(0);
    for (int i = 1; i < m; i++) {
        getline(cin, buf);
        parserow(i);
    }
    
    string cur;
    getline(cin, cur);

    int idx = 0;
    for (size_t i = 0; i < cur.size(); i++) {
        int delta;  
        cin >> delta;
        idx += delta;

        for (int j = 0; j < k; j++) {
            grid[idx++] = letters[conv(cur[i])][j];
        }
    }

    string target;
    getline(cin, target);
    getline(cin, target);

    auto cost = [](int pos, int let) {
        int start = pos - (k - 1);
        int ans = 0;
        for (int i = 0; i < k; i++) {
            int colgrid = grid[start + i];
            int collet = letters[let][i];
            ans += __builtin_popcount(colgrid ^ collet);
        }
        return ans;
    };

    auto cost0 = [](int start, int end) {
        int ans = 0;
        for (int i = start; i <= end; i++) {
            ans += __builtin_popcount(grid[i]);
        }
        return ans;
    };

    int tarlen = target.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tarlen; j++) {
            dp[i][j] = -1;
            par[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i >= k - 1) {
            dp[i][0] = cost(i, conv(target[0])) + cost0(0, i - k);
            par[i][0] = i - k + 1;
        }
    }

    for (int letidx = 1; letidx < tarlen; letidx++) {
        for (int i = 0; i < n; i++) {
            for (int space = smin; space <= smax; space++) {
                int prevlet = i - k - space;
                if (prevlet >= 0 && dp[prevlet][letidx - 1] != -1) {
                    int ndp = dp[prevlet][letidx - 1] + cost(i, conv(target[letidx])) + cost0(prevlet + 1, i - k);
                    if (dp[i][letidx] == -1 || ndp < dp[i][letidx]) {
                        dp[i][letidx] = ndp;
                        par[i][letidx] = space;
                    }
                }
            }
        }
    }

    int ans = -1;
    int anspos = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i][tarlen - 1] != -1) {
            if (ans == -1 || ans > dp[i][tarlen - 1] + cost0(i + 1, n - 1)) {
                ans = dp[i][tarlen - 1] + cost0(i + 1, n - 1);
                anspos = i;
            }
        }
    }

    vector <int> spaces;
    int pos = anspos;
    for (int i = tarlen - 1; i >= 0; i--) {
        spaces.push_back(par[pos][i]);
        pos -= par[pos][i] + k;
    }
    reverse(all(spaces));

    for (const auto& spc : spaces) {
        cout << spc << ' ';
    }
    cout << endl;

    return 0;
}

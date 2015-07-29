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
#define File "checkers"

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

int n, k;
char a[30][1000];
int len[30], lenc;
char cur[50];

bool make(int pos) {
    int l = len[pos] - 1;
    int r = lenc - 1;

    while (l >= 0 && r >= 0 && a[pos][l] == cur[r])
        l--, r--;

    if (l < 0 || r < 0) {
        a[pos][len[pos]++] = 'B';
        cur[lenc++] = 'W';
        return true;
    }

    cur[lenc++] = a[pos][l];
    a[pos][len[pos]++] = cur[r];

    return (a[pos][l] == 'W');  
}

int solve(int cnt) {
    int ans = 0;
    int slen[30];

    for (int i = 0; i < 30; i++)
        slen[i] = len[i];

    int slenc = lenc;

    for (int mask = 0; mask < (1 << n); mask++) {
        int tmp = 0;
        int cur_cnt = cnt;
        
        for (int i = 0; i < n; i++) {
            if (cur_cnt) {
                tmp += make(i);

                cur_cnt--;

                if ((mask & (1 << i)) && cur_cnt) {
                    tmp += make(i);
                    cur_cnt--;
                }
            }   
        }

        if (cur_cnt)
            tmp += solve(cur_cnt);

        ans = max(ans, tmp);

        for (int i = 0; i < n; i++)
            len[i] = slen[i];
        lenc = slenc;
    }   

    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        len[i] = strlen(a[i]);
    }

    cout << solve(k);

    return 0;
}

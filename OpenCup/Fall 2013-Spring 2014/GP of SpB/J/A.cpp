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
#define File "snakes2"

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

vector <int> table[50][50];
int type[50][50];
bool used[50][50];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int k;

    cin >> k;

    vector <vector <PII> > a(k);
    vector <int> l(k);

    for (int i = 0; i < k; i++) {
        cin >> l[i];
        a[i].resize(l[i]);

        for (int j = 0; j < l[i]; j++) {
            cin >> a[i][j].F >> a[i][j].S;
            table[a[i][j].F][a[i][j].S].push_back(i);
        }
    }   


    for (int z = 0; z < k; z++) {
        memset(used, 0, sizeof used);

        string ans = "";
        for (int i = 0; i < l[z]; i++) {
            PII &cur = a[z][i];

            if (table[cur.F][cur.S].size() == 2) {
                vector <int> c = table[cur.F][cur.S];

                if (c[0] == c[1]) {
                    if (used[cur.F][cur.S])
                        ans += '-';
                    else {
                        used[cur.F][cur.S] = true;
                        ans += '+';
                    }   
                } else {
                    int nmb = c[0] + c[1] - z;

                    if (nmb > z)
                        ans += '-';
                    else
                        ans += '+'; 
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}

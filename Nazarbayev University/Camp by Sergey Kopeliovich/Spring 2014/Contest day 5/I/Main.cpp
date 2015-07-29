/****************************************
**          Solution by NU #2          **
****************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "shop"

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
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int m, n, cnt, amount[maxn];
string s, t, prod[maxn];
map <string, int> store;

int ans = 0;
int cur = 0, pos = 0;
int loh_nurs = -1, loh_nurs_cnt = -1;
bool loh_nurs_came = false;
int used[maxn][maxn];
    
void take_new() {
    if (loh_nurs != -1) {
        cur = loh_nurs;
        loh_nurs = -1;
        loh_nurs_came = true;
    } else {
        cur = ++pos;
        loh_nurs_came = false;
    }
}

int main() {
    freopen(File".in", "r", stdin);
    //freopen(File".out", "w", stdout);
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> cnt >> t >> s;
        store[s] = cnt;
    }
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> amount[i] >> t >> prod[i];
    }
    
    while (cur < n) {
        if (store[prod[cur]] == 0) {
            cur = ++pos;
            loh_nurs_came = false;
        } else if (store[prod[cur]] < amount[cur]) {
            
            if (loh_nurs_came) {
                if (store[prod[cur]] == loh_nurs_cnt) {
                    store[prod[cur]] = 0;
                    take_new();
                } else {
                    loh_nurs_cnt = store[prod[cur]];
                    
                    if (loh_nurs != -1) {
                        swap(loh_nurs, cur);
                        loh_nurs_came = true;
                    } else {
                        loh_nurs = cur;
                        cur = ++pos;
                        loh_nurs_came = false;
                    }
                }
            } else {
                loh_nurs_cnt = store[prod[cur]];
                
                if (loh_nurs != -1) {
                    swap(loh_nurs, cur);
                    loh_nurs_came = true;
                } else {
                    loh_nurs = cur;
                    loh_nurs_came = false;
                    cur = ++pos;
                }
            }
            
        } else {
            store[prod[cur]] = store[prod[cur]] - amount[cur];
            
            take_new();
        }
        
        ans++;
        
//        assert(ans < 1000000);
    }
    
    cout << ans;
    
    return 0;
}

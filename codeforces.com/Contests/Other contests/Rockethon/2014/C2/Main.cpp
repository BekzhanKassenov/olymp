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

const int maxn = 200010;
int n, k;
PII a[maxn];

struct st {
    int num, cnt;
    bool win;

    st() { }
    
    st(int num, int cnt, bool win = true) : num(num), cnt(cnt), win(win) { }
    
    bool operator < (const st& ss) const {
        if (cnt != ss.cnt)
            return cnt < ss.cnt;
            
        if (num != 0 && ss.num != 0) {
            return win < ss.win;
        } else {
            if (num == 0)
                if (ss.win)
                    return true;
                else
                    return false;
            else
                if (!win)
                    return true;
                else
                    return false;
        }
    }
};

st b[maxn];

bool cmp(const PII& aa, const PII& bb) {
    return (aa.S < bb.S);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].F, &a[i].S);
    }   
    
    sort(a, a + n, cmp);
    
    for (int i = 0; i < n; i++)
        b[i + 1] = st(i + 1, a[i].F + 1, true);
 
    b[0] = st(0, 0, false);
    
    sort(b + 1, b + n + 1);
    
    int pos = 0;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (n - pos + 1 <= k) {
            cout << ans;
            return 0;
        }
        
        ans += a[i].S;
        
        int pos1 = 0;
        
        for (int j = 0; j <= n; j++) {
            if (b[j].num == i + 1) {
                b[j].cnt--;
                b[j].win = false;
                b[pos].cnt++;
                pos1 = j;
                break;
            }
        }
        
        while (pos1 > 0) {
            if (b[pos1] < b[pos1 - 1]) {
                swap(b[pos1], b[pos1 - 1]);
                if (pos1 - 1 == pos)
                    pos++;
                pos1--;
            } else
                break;
        }
        
        while (pos < n && b[pos + 1] < b[pos]) {
            swap(b[pos], b[pos + 1]);
            pos++;
        }
        
        cout << pos << ' ' << ans << endl;
        for (int k = 0; k <= n; k++)
            cout << b[k].num << ' ' << b[k].cnt << ' ' << a[b[k].num - 1].S << endl;
            
        cout << endl;
        
    }
    
    if (n - pos + 1 < k)    
        cout << ans;
    else
        cout << -1;
    
    return 0;
}

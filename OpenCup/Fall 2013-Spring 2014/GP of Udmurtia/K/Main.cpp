/****************************************
**          Solution by NU #2          **
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

int n, kk, m;

struct Point {
    int x, y;
    vector <int> _time;
};

struct Time {
    int val;
    int x, y;
    
    Time() { }
    
    Time(int val, int x, int y) : val(val), x(x), y(y) { } 
    
    bool operator < (const Time& t) const {
        return val < t.val;
    }
};

const int maxn = 60;

Point a[maxn];
Time b[maxn];
int time_sz;
vector <int> temp;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &kk);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &m);
        
        a[i]._time.resize(m);
        
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i]._time[j]);
            b[time_sz++] = Time(a[i]._time[j], a[i].x, a[i].y);
        }
        
        sort(all(a[i]._time));
    }
    
    sort(b, b + time_sz);
    
    ll ans = INF * 1ll * INF;
    
/*    for (int i = 0; i < time_sz; i++)
        cout << b[i].val << ' ' << b[i].x << ' ' << b[i].y << endl;
  */  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i].x > a[j].x)
                continue;
                
            for (int k = 0; k < n; k++) {
                if (a[k].x < a[i].x || a[k].x > a[j].x)
                    continue;
                    
                for (int l = 0; l < n; l++) {
                    if (a[l].x < a[i].x || a[l].x > a[j].x || a[k].y > a[l].y) {
                        continue;
                    }
                    
                    temp.clear();
                    
                    for (int q = 0; q < time_sz; q++) {
                        if (b[q].x < a[i].x || b[q].x > a[j].x || b[q].y < a[k].y || b[q].y > a[l].y)
                            continue;
                            
                        temp.push_back(b[q].val);
                    }
                    
                    for (size_t q = 0; q + kk - 1 < temp.size(); q++) {
                        ans = min(ans, (a[j].x - a[i].x) * 1ll * (a[l].y - a[k].y) * 1ll * (temp[q + kk - 1] - temp[q]));
                    }
                }
            }
        }
    }
    if (ans == INF * 1ll * INF)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}

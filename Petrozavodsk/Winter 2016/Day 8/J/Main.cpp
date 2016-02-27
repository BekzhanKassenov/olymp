/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#define N 222222

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

int n, m;
int a[N];
int b[N];

bool check(int x) {
    int d = 0;
    long long cur = 1;

    int j = m - x + 1;
    int i = n;
    for(;j <= m;) {
        while(d < b[j]) {
            long long ncur = 0;
            while(i >= 1 && cur) {
                ncur += a[i];
                cur--;
                i--;            
            }
            cur += ncur;
            d++;
        }
        if(cur > 0) {
            j++;
            cur--;
        }
        else break;
    }
    return j == m + 1;
}



int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];        
    }
    for(int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int l = 0, r = m + 1;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        //cout << mid << ' ' << check(mid) << endl;
        if(check(mid))
            l = mid;
        else 
            r = mid;
    }
    cout << l;
        
    return 0;
}

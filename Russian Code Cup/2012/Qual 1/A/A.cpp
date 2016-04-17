/****************************************
**     Solution by Bekzhan Kassenov    **
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

int a[12];
map <int, int> Map;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (true) {
        for (int i = 0; i < 12; i++) {
            scanf("%d", &a[i]);
        }
        
        if (a[0] == 0) {
            break;
        }
        
        Map.clear();
        
        for (int i = 0; i < 12; i++) {
            Map[a[i]]++;
        }
        
        bool ok = true;
        int cnt = 0;
        for (auto it: Map) {
            if (it.second % 4 != 0) {
                ok = false;
            }
            
            cnt += it.second / 4;
        }
        
        if (cnt != 3) {
            ok = false;
        }
        
        if (ok) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    
    return 0;
}

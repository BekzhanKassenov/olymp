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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int x;
    cin >> x;
    vector <int> a;
    a.push_back(x);

    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        cin >> x;
        
        if (x == 1) {
            cin >> x;
            a.push_back(x);
            cin >> x;
            a.push_back(x);
        } else {
            cin >> x;
            a.push_back(x);
        }
    }
    
    a.push_back(0);
    sort(all(a));
    
    int maxx = 0, minn = 0;
    
    for (size_t i = 1; i < a.size(); i++) {
        int diff = (a[i] - a[i - 1] - 1);
        
        maxx += diff;
        minn += (diff >> 1) + (diff & 1);
    }
    
    cout << minn << ' ' << maxx << endl;
    
    
    return 0;
}

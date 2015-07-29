/****************************************
**          Solution by NU #2          **
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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ans;
string str;

void calc(int l, int r) {
    if (l == r)
        return;
    
    while (str[l] == 'A' || str[l] == 'N') {
        l++;
        if (l == r)
            return;
    }

    while (str[r] == 'F' || str[r] == 'N') {
        r--;
        if (l == r)
            return;
    }

    if (str[l] != 'F' || str[r] != 'A')
        return;

    int index_l, index_r;

    for (int i = l; i <= r; i++) {
        if (str[i] != 'F') {
            index_l = i;
            break;
        }
    }
    for (int i = r; i >= l; i--) {
        if (str[i] != 'A') {
            index_r = i;
            break;
        }
    }
    if (index_l - l < r - index_r) {
        for (int i = index_l; i > l; i--) {
            swap(str[i], str[i - 1]);
            ans++;
        }
    }
    else {
        for (int i = index_r; i < r; i++) {
            swap(str[i], str[i + 1]);
            ans++;
        }
    }      
//    cout << str << " " << l << " " << r << " " << ans << endl;
    calc(l, r);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    cin >> n >> str;

    calc(0, n - 1);
    cout << ans;
    return 0;
}

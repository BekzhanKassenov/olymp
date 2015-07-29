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
typedef map <int, int> :: iterator iter;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[maxn], x, last;
map <int, int> Map;
ll ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        Map[x]++;
    }

    for (map <int, int> :: iterator it = Map.begin(); it != Map.end(); it++) {
        if (it -> S == 1)
            a[last++] = it -> F;
    }

    n = last;

    for (int i = 0; i < n; i++) {
        iter it = Map.find(a[i]);
        iter temp = it;
        int diff = INF;
        pair <int, int> tmp;
        iter first, last;

        if (it != Map.begin()) {
            temp--;

            if (diff > abs(it -> F - temp -> F)) {
                diff = abs(it -> F - temp -> F);
                tmp = *temp;
                first = temp;
                temp++;
                temp++;
                last = temp;
            }
        }

        if (it != --Map.end()) {
            temp = it;
            temp++;

            if (diff > abs(it -> F - temp -> F)) {
                diff = abs(it -> F - temp -> F);
                tmp = *temp;
                first = it;
                temp++;
                last = temp;
            }
        }

        cout << a[i] << ' ' << diff << endl;

        Map.erase(first, last);
        tmp.S++;
        Map.insert(tmp);
        ans += diff;
    }

    printf("%I64d", ans);

    return 0;
}

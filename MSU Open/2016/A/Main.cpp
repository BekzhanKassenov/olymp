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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    vector <int> temp;

    if (n < 10) {
        temp = vector <int>(a, a + n);
    } else {
        for (int i = 0; i < 3; i++) {
            temp.push_back(a[i]);
        }

        for (int i = n - 4; i < n; i++) {
            temp.push_back(a[i]);
        }
    }

    vector <int> vec;

    for (size_t i = 0; i < temp.size(); i++) {
        for (size_t j = i + 1; j < temp.size(); j++) {
            vec.push_back(temp[i] - temp[j]);
            vec.push_back(temp[j] - temp[i]);
        }
    }

    sort(all(vec));
    reverse(all(vec));

    printf("%d\n", vec[1]);
    
    return 0;
}

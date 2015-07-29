/******************************************
**          Solution by NU #2            **
******************************************/

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define File "kbest"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T x) {
    return (x * x);
}

int a[1000010];
int ans[1000010];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    vector <int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty()) {
            int pos = st.back();
            if (a[pos] <= a[i]) {
                ans[i] = max(ans[i], i - pos + ans[pos]);
                st.pop_back();
            } else
                break;  
        }
        st.push_back(i);
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);

    return 0;
}

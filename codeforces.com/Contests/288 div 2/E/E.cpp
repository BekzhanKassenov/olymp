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
const int MAXN = 610;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Open {
    int pos;
    int l, r;
} a[MAXN];

int n;
vector <Open> st;
char res[3 * MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
    }

    int pos = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (st.empty()) {
            a[pos].pos = i;
            st.push_back(a[pos]);
            pos++;
            res[i] = '(';
        } else {
            int dist = i - st.back().pos;
            int l = st.back().l;
            int r = st.back().r;

            if (l <= dist && dist <= r) {
                st.pop_back();
                res[i] = ')';
            } else if (dist < l) {
                a[pos].pos = i;
                st.push_back(a[pos]);
                pos++;
                res[i] = '(';
            } else {
                puts("IMPOSSIBLE");
                return 0;
            } 
        }
    }

    puts(res);
    
    return 0;
}

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
const int maxn = 3010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, a[maxn], pos[maxn], temp[maxn];
int need;

bool f(int i, int j) {
    if (a[j] == i && a[i] == j) {
        if (need == -1) {
            swap(a[i], a[j]);
            pos[a[i]] = i;
            pos[a[j]] = j;
            printf("%d %d ", i + 1, j + 1);
            return true;
        }

        if (n == 2)
            return false;

        for (int k = 0; k < n; k++) {
            if (k != i && k != j) {
                swap(a[k], a[i]);
                pos[a[k]] = k;
                pos[a[i]] = i;
                printf("%d %d ", min(k, i) + 1, max(k, i) + 1);
                return true;
            } 
        }
    } 

    if (a[i] == i || a[j] == j) {
        if (need == -1)
            return false;

        swap(a[i], a[j]);
        pos[a[j]] = j;
        pos[a[i]] = i;
        printf("%d %d ", i + 1, j + 1);
        return true;
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i]--;
        pos[a[i]] = i;
    }

    int cnt = 0;
    copy(a, a + n, temp);

    for (int i = 0; i < n; i++) {
        if (temp[i] != i) {
            int k = pos[i];

            swap(temp[i], temp[k]);
            pos[temp[i]] = i;
            pos[temp[k]] = k;
            cnt++;
        }
    }

    scanf("%d", &m);

    if (cnt > m) {
        printf("%d\n", cnt - m);
        need = -1;

        for (int i = 0; i < n && cnt > m; i++) {
            for (int j = 0; j < n && cnt > m; j++) {
                if (f(i, j))
                    cnt--;
            }
        }
    } else {
        printf("%d\n", m - cnt);
        need = 1;

        for (int i = 0; i < n && cnt < m; i++) {
            for (int j = 0; j < n && cnt < m; j++) {
                if (f(i, j))
                    cnt++;
            }
        }   
    }

    return 0;
}

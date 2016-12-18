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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int half(int n) {
    return (n + 1) / 2;
}

int n, w, k;
int a[MAXN];
int t[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &w, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    auto comp1 = [](int a, int b) {
        return (t[a] < t[b])
            || (t[a] == t[b] && a < b); 
    };
    set <int, decltype(comp1)> rest(comp1);

    auto comp2 = [](int a, int b) {
        return half(t[a]) < half(t[b])
            || (half(t[a]) == half(t[b]) && a < b);
    };
    set <int, decltype(comp2)> top(comp2);
    
    #define addRest(num) { \
        sumRest += t[num]; \
        ansRest += a[num]; \
        rest.insert(num); \
    }

    #define addTop(num) { \
        sumTop += half(t[num]); \
        ansRest += a[num]; \
        top.insert(num); \
    }

    #define removeRest(num) { \
        sumRest -= t[num]; \
        ansRest -= a[num]; \
        rest.erase(num); \
    }

    #define removeTop(num) { \
        sumTop -= half(t[num]); \
        ansTop -= a[num]; \
        top.erase(num); \
    }

    int r = 0;
    int sumRest = 0, sumTop = 0;
    int ansRest = 0, ansTop = 0;
    int ans = 0;
    for (int l = 0; l < n; l++) {
        while (r < n) {
            bool stop = true;
            if ((int)top.size() < w) {
                if (sumRest + sumTop + half(t[r]) <= k) {
                    addTop(r);
                    stop = false;
                }
            } else {
                int num = *top.begin();
                if (half(t[num]) < half(t[r])) {
                    if (sumRest + t[num] + sumTop - half(t[num]) + half(t[r]) <= k) {
                        removeTop(num);
                        addRest(num);
                        addTop(r);
                        stop = false;
                    }
                } else {
                    if (sumRest + t[r] + sumTop <= k) {
                        addRest(r);
                        stop = false;
                    }
                }
            }

            if (stop) {
                break;
            }

            r++;
        }

        ans = max(ans, ansTop + ansRest);
        if (rest.count(l)) {
            removeRest(l);
        } else {
            removeTop(l);
            if (!rest.empty()) {
                int mx = *(--rest.end());
                removeRest(mx);
                addTop(mx);
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}

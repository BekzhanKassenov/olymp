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

int n, m;
vector <int> even, odd;
int a[MAXN];

int get(int isOdd) {
    vector <int>& vec = isOdd ? odd : even;
    if (vec.empty()) {
        return -1;
    }

    int ans = vec.back();
    vec.pop_back();
    return ans;
}

void check(int pos) {
    if (a[pos] == -1) {
        puts("-1");
        exit(0);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int cntEven = 0, cntOdd = 0;

    set <int> dupl;
    set <int> input;
    for (int i = 0; i < n; i++) {
        if (input.count(a[i])) {
            dupl.insert(i);
        } else {
            input.insert(a[i]);
        }

        if (a[i] & 1) {
            cntOdd++;
        } else {
            cntEven++;
        }
    }       

    auto it = input.cbegin();
    for (int i = 1; i <= m && ((int)even.size() <= n / 2 || (int)odd.size() <= n / 2); i++) {
        if (it != input.end() && i == *it) {
            it++;
            continue;
        }

        if (i & 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }

    #define doEven(pos) \
        bool change = a[pos] & 1; \
        a[pos] = get(0); \
        check(pos); \
        ans++; \
        if (change) { \
            cntOdd--; \
            cntEven++; \
        } \

    #define doOdd(pos) \
        bool change = !(a[pos] & 1); \
        a[pos] = get(1); \
        check(pos); \
        ans++; \
        if (change) { \
            cntEven--; \
            cntOdd++; \
        } \

    int ans = 0;
    for (int pos : dupl) { 
        if (cntEven != cntOdd) {
            if (cntEven > cntOdd) {
                doOdd(pos);
            } else {
                doEven(pos);
            }
        } else {
            if (a[pos] & 1) {
                doOdd(pos);
            } else {
                doEven(pos);
            }
        }
    }
    
    for (int i = 0; i < n && cntEven > cntOdd; i++) {
        if (!(a[i] & 1)) {
            doOdd(i);
        }
    }

    for (int i = 0; i < n && cntEven < cntOdd; i++) {
        if (a[i] & 1) {
            doEven(i);
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], " \n"[i == n]);
    }

    return 0;
}

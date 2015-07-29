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

long long sum1, sum2, x;
vector <long long> vec1, vec2;
int n;
int last = -1;

bool cmp(const vector <long long>& a, const vector <long long>& b) {
    for (size_t i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] > b[i]) {
            return 1;
        }

        if (a[i] < b[i]) {
            return -1;
        }
    }

    if (a.size() > b.size()) {
        return 1;
    }

    if (a.size() < b.size()) {
        return -1;
    }

    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &x);

        if (x < 0) {
            sum2 -= x;
            vec2.push_back(-x);
            last = 2;
        } else {
            sum1 += x;
            vec1.push_back(x);
            last = 1;
        }
    }

    if (sum1 != sum2) {
        if (sum1 > sum2) {
            puts("first");
        } else {
            puts("second");
        }
    } else if (vec1 != vec2) {
        if (vec1 > vec2) {
            puts("first");
        } else {
            puts("second");
        }
    } else {
        if (last == 1) {
            puts("first");
        } else {
            puts("second");
        }
    }
    
    return 0;
}

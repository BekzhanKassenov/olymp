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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Compare {
    bool operator () (const pair <int, int>& a, const pair <int, int>& b) const {
        return a.first < b.first;        
    }
};

int n;
int a[MAXN];
multiset <pair <int, int>, Compare> Set;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        Set.insert(make_pair(a[i], i + 1));
    }
    
    sum /= n / 2;
    
    while (!Set.empty()) {
        int val = Set.begin()->first;
        int num1 = Set.begin()->second;
        Set.erase(Set.begin());
        auto it = Set.find(make_pair(sum - val, 0));
        int num2 = it->second;
        Set.erase(it);
        printf("%d %d\n", num1, num2);
    }

    return 0;
}
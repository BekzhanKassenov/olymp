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
const int lim = 1e5;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ll x, k;
int nb;
vector <ll> a, b;
map <ll, vector <ll> > divs;
bool flag;

inline void fact(ll n) {
    if (n == 1) {
        b.push_back(1);
        nb++;
        return;
    }

    if (!divs.count(n)) {
        vector <ll>& t = divs[n];

        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                t.push_back(i);

                if (i * i != n)
                    t.push_back(n / i);
            }
        }

        sort(all(t));
    }

    vector <ll>& t = divs[n];

    for (size_t i = 0; i < t.size(); i++) {
        b.push_back(t[i]);
        nb++;
        
        if (nb > lim)
            break;

        flag &= ((int)i < lim && t[i] != 1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%I64d %I64d", &x, &k);

    if (x == 1) {
        puts("1");
        return 0;
    }

    if (k > lim) {
        for (int i = 0; i < lim; i++) {
            printf("1 ");
        }

        puts("");
        return 0;
    }

    a.push_back(x);

    while (k--) {
        cerr << k << endl;
        flag = true;

        for (size_t i = 0; i < a.size(); i++) {
            if (nb > lim)
                break;
            
            fact(a[i]);
        }

        if (nb > lim)
            b.resize(lim);

        a.swap(b);
        b.clear();
        nb = 0;

        if (flag)
            break;
    }

    for (size_t i = 0; i < a.size(); i++)
        printf("%I64d ", a[i]);

    return 0;
}

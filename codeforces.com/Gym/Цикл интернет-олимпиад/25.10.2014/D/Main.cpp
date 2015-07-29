/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "divisors"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXP = 1300;
const int MAXN = 10000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

vector <int> primes;
int tree[MAXP][MAXN];
int a[MAXP][MAXN];
int n, m;
int d[MAXP];
int x, pos, type, l, r;

void build() {
    for (int i = 2; i <= 10000; i++) {
        if (prime(i))
            primes.push_back(i);
    }
}

void update(int *t, int pos, int val) {
    for (int i = pos; i < n; i |= i + 1) {
        t[i] += val;
    }
}

int sum(int *t, int pos) {
    int result = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        result += t[i];
    }

    return result;
}

int sum(int *t, int l, int r) {
    int result = sum(t, r);

    if (l != 0)
        result -= sum(t, l - 1);

    return result;
}

void fact(int *divs, int n) {
    for (size_t i = 0; i < primes.size(); i++) {
        divs[i] = 0;

        while (n % primes[i] == 0) {
            divs[i]++;
            n /= primes[i];
        }
    }
}

void update(int *divs, int pos) {
    for (size_t i = 0; i < primes.size(); i++) {
    	if (divs[i] != a[i][pos]) {
        	update(tree[i], pos, divs[i] - a[i][pos]);
        	a[i][pos] = divs[i];
        }
    }
}

int get(int l, int r) {
    long long res = 1;

    for (size_t i = 0; i < primes.size(); i++) {
        long long s = sum(tree[i], l, r);
        res = (res * (s + 1)) % MOD;
    }

    return res;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    build();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        fact(d, x);
        update(d, i);
    }

    scanf("%d", &m);

    while (m--) {
        scanf("%d", &type);

        if (type == 0) {
            scanf("%d%d", &pos, &x);
            pos--;
            fact(d, x);
            update(d, pos);
        } else {
            scanf("%d%d", &l, &r);
            printf("%d\n", get(l - 1, r - 1));
        }
    }

    return 0;
}
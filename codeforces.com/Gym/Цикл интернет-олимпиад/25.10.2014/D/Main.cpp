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
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXP = 1300;
const int MAXN = 50010;

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
int ppos[MAXN];
int tree[MAXP][MAXN];
int a[MAXN];
int n, m;
int x, pos, type, l, r;

void build() {
    for (int i = 2; i <= 10000; i++) {
        if (prime(i)) {
            ppos[i] = primes.size();
            primes.push_back(i);
        }
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
    return sum(t, r) - sum(t, l - 1);
}

void fact(int pos, int num, int add) {
    for (size_t i = 0; i < primes.size() && sqr(primes[i]) <= num && num > 1; i++) {
        int cnt = 0;
        while (num % primes[i] == 0) {
            cnt += add;
            num /= primes[i];
        }

        if (cnt != 0) {
            update(tree[i], pos, cnt);
        }
    }

    if (num > 1) {
        update(tree[ppos[num]], pos, add);
    }
}

void update(int pos, int num) {
    fact(pos, a[pos], -1);
    a[pos] = num;
    fact(pos, a[pos], 1);
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
        int x;
        scanf("%d", &x);
        update(i, x);
    }

    scanf("%d", &m);

    while (m--) {
        scanf("%d", &type);

        if (type == 0) {
            scanf("%d%d", &pos, &x);
            update(pos - 1, x);
        } else {
            scanf("%d%d", &l, &r);
            printf("%d\n", get(l - 1, r - 1));
        }
    }

    return 0;
}

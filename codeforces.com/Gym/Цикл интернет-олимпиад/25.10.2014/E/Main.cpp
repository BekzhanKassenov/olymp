/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "game"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline long long sqr(T n) {
    return 1ll * n * n;
}

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

vector <int> d;
vector <vector <int> > divs;

const vector <int>& getvec(int num) {
    static vector <int> empty;
    if (num == 1) {
        return empty;
    }

    int pos = lower_bound(all(d), num) - d.begin();
    return divs[pos];
}

void prepare(int a, int b) {
    auto factorize = [](int a) {
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                d.push_back(i);
                d.push_back(a / i);
            }
        }
        d.push_back(a);
    };
    
    factorize(a);
    factorize(b);

    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    divs.resize(d.size());

    for (size_t i = 0; i < d.size(); i++) {
        for (int q : d) {
            if (sqr(q) > d[i]) {
                break;
            }

            if (d[i] % q == 0) {
                divs[i].push_back(q);
                if (sqr(q) != d[i]) {
                    divs[i].push_back(d[i] / q);
                }
            }
        }

        divs[i].push_back(d[i]);
        sort(all(divs[i]));
        reverse(all(divs[i]));
    }
}

namespace std {
    template <>
    struct hash <pair <int, int> > {
        size_t operator() (const pair <int, int>& p) const {
            size_t result = p.first;
            return (result << 32) ^ p.second;
        }
    };
}

unordered_map <pair <int, int>, bool> dp;

bool win(int a, int b) {
    if (a > b) {
        swap(a, b);
    }

    pair <int, int> p(a, b);
    if (dp.count(p)) {
        return dp[p];
    }

    bool& ans = dp[p];
    ans = false;

    int g = gcd(a, b);

    for (int d : getvec(g)) {
        if (!win(a / d, b / d)) {
            return ans = true;
        }
    }
    
    for (int d : getvec(a)) {
        if (!win(a / d, b)) {
            return ans = true;
        }
    }

    for (int d : getvec(b)) {
        if (!win(a, b / d)) {
            return ans = true;
        }
    }

    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int a, b;
    scanf("%d%d", &a, &b);

#ifdef Local
    clock_t start = clock();
#endif

    prepare(a, b);

    if (win(a, b)) {
        puts("Lucky wins");
    } else {
        puts("Alf wins");
    }

#ifdef Local
    cerr << "Time elapsed: " << (clock() - start) / CLOCKS_PER_SEC << endl;
    /*
    for (auto p : dp) {
        fprintf(stderr, "dp[%d][%d]=%d\n", p.first.first, p.first.second, p.second);
    }
    */
#endif

    return 0;
}

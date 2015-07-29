/****************************************
**      Solution by NU: Black Kex      **
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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const long long MOD1 = 1000 * 1000 * 1000 + 7;
const long long MOD2 = 1000 * 1000 * 1000 + 9;
const long long BASE1 = 29;
const long long BASE2 = 31;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN], t[MAXN];
long long power1[MAXN];
long long power2[MAXN];

struct Hasher {
    char *s;
    pair <long long, long long> hash[MAXN];

    Hasher() { }

    void set_string(char *str) {
        s = str;

        hash[0].first = s[0];
        hash[0].second = s[0];

        for (int i = 1; i < n; i++) {
            hash[i].first = (hash[i - 1].first + s[i] * power1[i]) % MOD1;
            hash[i].second = (hash[i - 1].second + s[i] * power2[i]) % MOD2;
        }
    }

    pair <long long, long long> subhash(int l, int r) {
        pair <long long, long long> result = hash[r];

        if (l > 0) {
            result.first = ((result.first - hash[l - 1].first) % MOD1 + MOD1) % MOD1;
            result.second = ((result.second - hash[l - 1].second) % MOD2 + MOD2) % MOD2;
        }

        return result;
    }

    long long add_letter(int pos, char let) {
        pair <long long, long long> result(0, 0);
        pair <long long, long long> sub = subhash(pos, n - 1);

        if (pos > 0) {
            result = hash[pos - 1];
        }

        result.first = (result.first + sub.first * BASE1) % MOD1;
        result.second = (result.second + sub.second * BASE2) % MOD2;

        result.first = (result.first + let * power1[pos]) % MOD1;
        result.second = (result.second + let * power2[pos]) % MOD2;

        return (result.first << 31) ^ result.second;
    }
};

Hasher hasher;
vector <long long> vec, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &n);

    gets(s);
    gets(t);

    power1[0] = 1;
    power2[0] = 1;

    for (int i = 1; i <= n; i++) {
        power1[i] = (power1[i - 1] * BASE1) % MOD1;
        power2[i] = (power2[i - 1] * BASE2) % MOD2;
    }

    hasher.set_string(s);
    for (int i = 0; i <= n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            vec.push_back(hasher.add_letter(i, c));
        }
    }

    sort(all(vec));

    hasher.set_string(t);
    for (int i = 0; i <= n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            long long hash = hasher.add_letter(i, c);
            if (binary_search(all(vec), hash)) {
                ans.push_back(hash);
            }
        }
    }

    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());

    printf("%d\n", ans.size());

    return 0;
}

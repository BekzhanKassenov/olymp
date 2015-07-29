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

int n;
string s;
string a[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool cmp(const string& s, const string& t) {
    if (s.size() != t.size())
        return false;

    for (size_t i = 0; i < s.size(); i++)
        if (s[i] != '.' && s[i] != t[i])
            return false;

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    cin >> n;

    cin >> s;

    for (int i = 0; i < 8; i++) {
        if (cmp(s, a[i])) {
            cout << a[i] << endl;
            return 0;
        }
    }

    return 0;
}

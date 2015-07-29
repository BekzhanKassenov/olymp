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

void inc(string& s) {
    int n = s.size();

    s[n - 1]++;

    for (int i = n - 1; i > 0 && s[i] == 'z' + 1; i--) {
        s[i] = 'a';
        s[i - 1]++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    string s, t;
    cin >> s >> t;

    string mid = s;
    inc(mid);

    if (s < mid && mid < t) {
        cout << mid << endl;
    } else {
        cout << "No such string" << endl;
    }

    return 0;
}

/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    string s;
    cin >> s;

    bool has_lower = false, has_upper = false, has_digit = false;

    for (size_t i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            has_digit = true;
        else if (islower(s[i]))
            has_lower = true;
        else if (isupper(s[i]))
            has_upper = true;
    }

    if (s.size() >= 5u && has_lower && has_digit && has_upper)
        cout << "Correct" << endl;
    else
        cout << "Too weak" << endl;

    return 0;
}

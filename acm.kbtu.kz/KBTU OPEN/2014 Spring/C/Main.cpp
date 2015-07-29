/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "easy"

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

bool check(const string& s, int pos) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
        if (l == pos)
            l++;
        else if (r == pos)
            r--;

        if (s[l] != s[r])
            return false;

        l++, r--;
    }

    return true;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    string s;
    cin >> s;

    for (size_t i = 0; i < s.size(); i++) {
        if (check(s, i)) {
            cout << "yes" << endl;
            s.erase(s.begin() + i);
            cout << s << endl;
            return 0;
        }
    }

    cout << "no" << endl;

    return 0;
}

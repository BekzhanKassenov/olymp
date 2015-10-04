/****************************************
**          Solution by NU #2          **
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
const int MAXN = 1 << 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, lev, pos;
string s[MAXN * 4];
string table;
map <string, int> highest;

int Q;
string q1, q2;

bool parent(const string& s1, const string& s2) {
    int pos = highest[s2];

    while (pos > 0) {
        if (s[pos] == s1) {
            return true;
        }

        pos >>= 1;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> lev;
    n = (1 << lev);

    for (int i = 0; i < n; i++) {
        cin >> s[i + n];
        highest[s[i + n]] = i + n;
    }

    cin >> table;

    for (int i = lev - 1; i >= 0; i--) {
        for (int j = (1 << i); j < (1 << (i + 1)); j++) {
            if (table[pos] == 'W') {
                s[j] = s[2 * j];
            } else {
                s[j] = s[2 * j + 1];
            }

            highest[s[j]] = j;
            pos++;
        }
    }

    cin >> Q;

    while (Q--) {
        cin >> q1 >> q2;

        if (parent(q1, q2)) {
            cout << "Win" << endl;
        } else if (parent(q2, q1)) {
            cout << "Lose" << endl;
        } else {
            cout << "Unknown" << endl;
        }
    }

    return 0;
}

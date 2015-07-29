/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "shortest-accepted"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
string s;
int n, pos;

string term();
string expr();
string fact();
string formula();

string term() {
    string res;

    if (s[pos] == '(') {
        pos++;
        res = expr();
        pos++;
    } else if (isalpha(s[pos])) {
        if (isalpha(s[pos])) {
            res.append(1, s[pos]);
            pos++;
        }
    } else {
        res.clear();
        pos++;
    }

    while (s[pos] == '*') {
        res.clear();
        pos++;
    }

    return res;
}

string fact() {
    string res;

    while (s[pos] == '(' || isalpha(s[pos]) || s[pos] == '$') {
        res += term();
    }

    return res;
}

string expr() {
    string res = fact();

    while (s[pos] == '|') {
        pos++;
        string other = fact();

        if (other.size() < res.size() || (other.size() == res.size() && other < res)) {
            res = other;
        }
    } 

    return res;
}

string formula() {
    return expr();
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen(File".in", "r", stdin);
    
    cin >> T;

    while (T--) {
        cin >> s;
        n = s.size();
        pos = 0;
        string res = formula();

        if (!res.empty()) {
            cout << res << endl;
        } else {
            cout << '$' << endl;
        }
    }

    return 0;
}

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

string s;
int x, n, 

char c;

void oppose(string& st) {
    if (st == ">=")
        st = "<";
    else if (st == "<=")
        st = ">";
    else if (st == ">")
        st = "<=";
    else
        st = ">=";
}        

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> x >> c;

        if (c == 'N')
            oppose(s);
        
        if (s == ">") {
            s = ">=";
            x++;
        } else if (s == "<") {
            s = "<=";
            x--;
        }

        if (s == ">=") {
            l = max(l, x);
        } else {
            r = min(r, x);
        }
    } 

    if (l <= r) {
        cout << l;
    } else {
        cout << "Impossible";
    }

    return 0;
}

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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

string s;
vector <string> ans[MAXN];
int D;

void dfs(size_t& pos, int depth = 0) {
    D = max(D, depth + 1);

    size_t start = pos;
    size_t len = 0;
    while (pos < s.size() && s[pos] != ',') {
        pos++;
        len++;
    }
    pos++; // ,
    ans[depth].emplace_back(s.substr(start, len));

    int num = 0;
    while (pos < s.size() && s[pos] != ',') {
        num *= 10;
        num += s[pos++] - '0';
    }

    if (pos < s.size() && s[pos] == ',') {
        pos++; // ,
    }

    for (int i = 0; i < num; i++) {
        dfs(pos, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    getline(cin, s);

    size_t pos = 0;
    while(pos < s.size()) {
        dfs(pos);
    }

    cout << D << endl;
    for (int i = 0; i < D; i++) {
        for (const string& s : ans[i]) {
            cout << s << ' ';
        }
        cout << endl;
    }

    return 0;
}

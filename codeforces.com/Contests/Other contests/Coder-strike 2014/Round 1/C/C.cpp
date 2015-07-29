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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, len;
string s[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    ios_base :: sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    len = s[0].size();

    for (int i = 0; i < len; i++) {
        vector <char> temp;

        for (int j = 0; j < n; j++) {
            if (s[j][i] != '?') {
                temp.push_back(s[j][i]);
            }
        }

        sort(all(temp));
        temp.resize(unique(all(temp)) - temp.begin());

        if (temp.empty())
            cout << 'a';
        else if (temp.size() == 1u)
            cout << temp[0];
        else
            cout << '?';
    }

    cout << endl;
    
    return 0;
}

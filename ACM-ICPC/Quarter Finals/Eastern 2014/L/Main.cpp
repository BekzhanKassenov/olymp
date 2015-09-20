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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int ans, pos;
map <string, int> Map;

int calc (string s) {
    int dest = Map[s];

    int res = abs(pos - dest);
    pos = dest;

    return res;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int n;
    string s;

    Map["Alice"] = Map["Phil"] = Map["Phoebus"] = 1;
    Map["Ariel"] = Map["Peter"] = Map["Ralph"] = 1;
    Map["Aurora"] = Map["Olaf"] = Map["Robin"] = 1;
    Map["Bambi"] = Map["Mulan"] = Map["Silver"] = 2;
    Map["Belle"] = Map["Mowgli"] = Map["Simba"] = 2;
    Map["Bolt"] = Map["Mickey"] = Map["Stitch"] = 2;
    Map["Dumbo"] = Map["Kuzko"] = Map["Tarzan"] = 3;
    Map["Genie"] = Map["Kida"] = Map["Tiana"] = 3;
    Map["Jiminy"] = Map["Kenai"] = Map["Winnie"] = 3;

    cin >> n;

    pos = 1;
    for (int i = 0; i < n; i++) {
        cin >> s;

        ans += calc (s);
    }

    cout << ans;
    
    return 0;
}

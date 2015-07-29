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

string s;
vector <int> ab, ba;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    getline(cin, s);

    for (size_t i = 0; i < s.size(); i++) {
        if (s.substr(i, 2) == "AB") {
            ab.push_back(i);
        } else if (s.substr(i, 2) == "BA") {
            ba.push_back(i);
        }
    }

    if (ab.size() > 10u && ba.size() > 10u) {
        puts("YES");
        return 0;
    }

    for (size_t i = 0; i < ab.size(); i++) {
        for (size_t j = 0; j < ba.size(); j++) {
            if (ab[i] + 1 != ba[j] && ab[i] != ba[j] + 1) {
                puts("YES");
                return 0;
            }     
        }
    }

    puts("NO");
    
    return 0;
}

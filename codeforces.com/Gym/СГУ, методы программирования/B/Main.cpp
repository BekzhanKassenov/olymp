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
#define File ""

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

vector <short> setstr[1 << 11];

void build() {
    for (int mask = 0; mask < (1 << 11); mask++) {
        for (short i = 0; i < 11; i++) {
            if (mask & (1 << i))
                setstr[mask].push_back(i + 1);
        }
    }
}

int n, k;

vector <vector <short> > cur;
set <vector <vector <short> > > ans;

void go(int mask, short gl = 0) {
    if (gl == k - 1) {
        vector <vector <short> > tmp = cur;
        tmp.push_back(setstr[mask]);
        sort(all(tmp));
        ans.insert(tmp);
        return;
    }

    int pos = __builtin_ctz(mask);

    for (int ms = mask; ms > 0; ms = (ms - 1) & mask) {
        if (ms == mask || !(ms & (1 << pos)))
            continue;
        
        cur.push_back(setstr[ms]);
        go(mask - ms, gl + 1);
        cur.pop_back();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    build();

    cin >> n >> k;

    go((1 << n) - 1);

    for (set <vector <vector <short> > > :: iterator it = ans.begin(); it != ans.end(); it++) { 
        for (size_t j = 0; j < it -> size(); j++) {

            cout << '[';
            cout << (*it)[j][0];

            for (size_t k = 1; k < (*it)[j].size(); k++)
                cout << ',' << (*it)[j][k];
            cout << ']';
        }
        cout << endl;
    }

    return 0;
}

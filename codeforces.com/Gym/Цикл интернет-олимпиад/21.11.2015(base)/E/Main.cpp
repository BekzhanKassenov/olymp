/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "notepad"

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

string lastK(const string& s, int k) {
    if (k > (int)s.size()) {
        return s;
    }

    return s.substr(s.size() - k, k);
}

int main() {
    ios_base :: sync_with_stdio(false);

    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector <string> data(n);
    string clipboard;
    int curDoc = 0;

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (input == "Backspace") {
            if (!data[curDoc].empty()) {
                data[curDoc].pop_back();
            }
        } else if (input == "Copy") {
            clipboard = lastK(data[curDoc], k);
        } else if (input == "Paste") {
            data[curDoc] += clipboard;
        } else if (input == "Next") {
            curDoc = (curDoc + 1) % n;
        } else {
            // letter
            data[curDoc].push_back(input[0]);
        }
    }

    if (data[curDoc].empty()) {
        cout << "Empty" << endl;
    } else {
        cout << lastK(data[curDoc], k) << endl;
    }

    return 0;
}

/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "black"

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

int n, m, s, k;
string line;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> m >> n >> s >> k;

    cin >> line;

    bool ok = false;
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == '*') {
            ok = true;
            break;
        }
    } 

    // There are no any black squares
    if (!ok) {
        // Can put only to above
        if (k > s && (m - k) < s) {
            if (k - s == 1) {
                if (s == n) {
                    cout << "Unique" << endl;
                } else {
                    cout << "Ambiguous" << endl;
                }
            } else {
                cout << "Ambiguous" << endl;
            }                    
        }
        // Can put only to below
        else if (k <= s && (m - k) >= s) {
            if (m - k - s == 0) {
                if (s == n) {
                    cout << "Unique" << endl;
                } else {
                    cout << "Ambiguous" << endl;
                }
            } else {
                cout << "Ambiguous" << endl;
            }                    
        }
        // Can put to both sides 
        else if (k > s && (m - k) >= s) {
            cout << "Ambiguous" << endl;
        }
        // No solution otherwise
        else {
            cout << "Impossible" << endl;
        }
        return 0;
    }

    string tmp = "";
    int sid = 0, fid = (int)line.length() - 1;

    while (line[sid] != '*' && sid < (int)line.length()) {
        sid++;
    }
    
    while (line[fid] != '*' && fid >= 0) {
        fid--;
    }

    if (sid >= (int)line.length() || fid <= -1) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = sid; i <= fid; i++) {
        tmp += line[i];
        if (line[i] != '*') {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if ((int)tmp.length() != s) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Already there
    if ((int)tmp.length() == 1) {
        cout << "Unique" << endl;
    }
    // Can make only down
    else if (k == 1) {
        cout << "Unique" << endl;
    }
    // Can make only up
    else if (k == m) {
        cout << "Unique" << endl;        
    }
    else if (s == m) {
        cout << "Unique" << endl;
    }
    // Can make both up & down
    else {
        cout << "Ambiguous" << endl;    
    }

    return 0;
}

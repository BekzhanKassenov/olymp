/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "monkey"

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

string change(const string& s) {
    string res;
    
    for (size_t i = 0; i < s.size(); i++) {
        if (res.empty() || res.back() != s[i])
            res += s[i];
    }
    
    sort(all(res));
    
    return res;
}

map <string, vector <string> > Map;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n;
        
        string s;
        Map.clear();
        
        for (int i = 0; i < n; i++) {
            cin >> s;
            Map[change(s)].push_back(s);
        }
        
        cin >> m;
        
        for (int i = 0; i < m; i++) {
            cin >> s;
            string t = change(s);
            
            if (Map[t].empty()) {
                cout << "No matches found." << endl;
                continue;
            }
            
            sort(all(Map[t]));
            
            cout << "Did you mean:" << endl;
            
            for (size_t j = 0; j < Map[t].size(); j++)
                cout << Map[t][j] << '?' << endl;
        }
    }
    
    return 0;
}

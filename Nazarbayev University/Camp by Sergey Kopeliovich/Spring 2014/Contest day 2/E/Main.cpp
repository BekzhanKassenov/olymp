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
#define File "numbers"

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

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    string s;
    cin >> s;
    
    string t;
    t += s[0];
    t += s[4];
    t += s[5];
    
    sort(all(t));
    
    string tt;
    tt += s[1];
    tt += s[2];
    tt += s[3];
    
    sort(all(tt));
    
    set <string> Set;
    
    stringstream str;
    int ans = 0;
    
    do {
        do {
            string ss;
            ss += t[0];
            ss += tt;
            ss += t[1];
            ss += t[2];
            
            if (Set.find(ss) == Set.end()) {
                Set.insert(ss);
                str << ss << endl;
                ans++;
            }
            
        } while (next_permutation(all(tt)));
    } while (next_permutation(all(t)));
    
    cout << ans << endl << str.str();
    
    return 0;
}

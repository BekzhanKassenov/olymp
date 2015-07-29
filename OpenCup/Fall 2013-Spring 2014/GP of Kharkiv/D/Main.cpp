/****************************************
**         Solution by NU #2           **
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

string calc[] = {
                 "a",
                 "ab",
                 "aba",
                 "abac", 
                 "abaca", 
                 "abacab", 
                 "abacaba", 
                 "abacabca", 
                 "abacabcac", 
                 "abacabcacb", 
                 "abacabcacba", 
                 "abacabcacbab", 
                 "abacabcacbabc", 
                 "abacabcacbabca", 
                 "abacabcacbabcab", 
                 "abacabcacbabcaba", 
                 "abacabcacbabcabac", 
                 "abacabcacbabcabaca", 
                 "abacabcacbabcabacab", 
                 "abacabcacbabcabacabc",
                 "abacabcacbabcabacabca", 
                 "abacabcacbabcabacabcac",
               }; 

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int n;
    
    cin >> n;
    
    if (n <= 22) {
        if (n == 1)
            cout << 1 << endl;
        else if (n < 4)
            cout << 2 << endl;
        else
            cout << 3 << endl;

        cout << calc[n - 1] << endl; 
    } else {
        string s = calc[21];
        
        int len = s.size();
        
        int ans = 0;
        
        for (char c = 'd'; len < n; c++) {
            string temp = s;
            ans = c - 'a' + 1;
            
            for (int j = 0; j < len; j++)
                if (s[j] == 'a')
                    temp[j] = c;
                    
            s += temp;
            len <<= 1;
        }
        
        cout << ans << endl;
        
        assert(ans <= 26);
        
        for (int i = 0; i < n; i++) {
            putchar(s[i]);
        }
    }
    return 0;
}

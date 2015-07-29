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
#define File "legend"

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

const char* snd = "Sandro";
char s[2010];
int n, ans = INF;

bool small(char c) {
    return c >= 'a' && c <= 'z';
}

char lower(char c) {
    if (!small(c)) 
        return 'a' + c - 'A';
        
    return c;
}

int make(int pos) {
    int asn = 0;
    
    for (int i = pos; i < pos + 6; i++) {
        if (s[i] != snd[i - pos]) {
            if (small(s[i]) != small(snd[i - pos])) {
                asn += 5 + 5 * (lower(s[i]) != lower(snd[i - pos]));
            } else
                asn += 5;
        }
    }
    
    return asn;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(s);
    
    n = strlen(s);
    
    for (int i = 0; i + 6 <= n; i++) {
        ans = min(ans, make(i));
    }
    
    cout << ans;
    return 0;
}

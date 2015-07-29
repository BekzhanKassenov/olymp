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

int b[20];

bool okay (const string& a) {
    int n = a.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; i + 2 * j - 1 < n; j++) {
            bool flag = true;
            
            for (int k = 0; k < j; k++)
                if (a[i + k] != a[i + k + j])
                    flag = false;
                    
            if (flag)
                return false;
        }
    }
    
    return true;
}

set <pair <string, int> > st;

char get_min(char c) {
    if (c == 'a')
        return 'b';

    return 'a'; 
}

char get_max(char c) {
    if (c == 'c')
        return 'b';
        
    return 'c';
}

void show(int mask, int len) {
    string res;
    
    while (mask) {
        res += '0' + (mask & 1);
        mask >>= 1;
    }
    
    while (res.size() < len)
        res += '0';
    
    //reverse(all(res));
    
    cout << res << endl;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    for (int n = 4; n <= 22; n++) {
        memset(b, 0, sizeof b);
        st.clear();
        
        for (int mask = 0; mask < (1 << (n - 1)); mask++) {
            string res = "a";
            
            for (int i = 0; i < n - 1; i++) {
                if (mask & (1 << i))
                    res += get_max(res[i]);
                else
                    res += get_min(res[i]);   
            }
            
            if (okay(res))
                st.insert(MP(res, mask));
        }
        
        cout << '"' << st.begin() -> F << '"' << ", ";
        //show(st.begin() -> S, n - 1);
    }
    return 0;
}

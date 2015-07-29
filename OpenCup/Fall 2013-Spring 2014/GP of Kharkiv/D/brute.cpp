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

bool okay (int a[], int n) {
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

set <string> st;

void shift(string& s) {
    for (size_t i = 0; i < s.size(); i++) {
        s[i] = 'a' + (s[i] - 'a' + 2) % 3;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int ans = 0;

    string s = "abac";
    
    for (int i = 0; i < 3; i++) {
        string temp = s;
        reverse(all(temp));
        shift(temp);
        s += temp;
    }
    
    cout << s << endl;
    
    return 0;
}

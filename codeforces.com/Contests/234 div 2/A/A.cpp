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

bool check(const string& s, int a) {
    int b = 12 / a;
    vector <vector <char> > arr(a, vector <char> (b));
    
    for (size_t i = 0; i < s.size(); i++) {
        arr[i / b][i % b] = s[i];
    }
    
    for (int i = 0; i < b; i++) {
        bool flag = true;
        
        for (int j = 0; j < a; j++)
            if (arr[j][i] != 'X')
                flag = false;
                
        if (flag)   
            return true;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;
    
    cin >> n;
    
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        stringstream ss;
        int res = 0;
        
        for (int j = 1; j <= 12; j++)
            if (12 % j == 0 && check(s, j)) {
                ss << j << 'x' << 12 / j << ' ';
                res++;
            }
            
        cout << res << ' ' << ss.str() << endl;
    }
    
    return 0;
}

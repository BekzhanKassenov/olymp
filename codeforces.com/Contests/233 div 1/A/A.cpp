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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int a, b;
    
    cin >> a >> b;
    
    string res;
    
    int n = a + b;
    
    if (a < b) {
        int cnt = b / (a + 1);
        
        for (int i = 0; i < b % (a + 1); i++) {
            for (int j = 0; j < cnt + 1; j++)
                res += 'x';
                
            res += 'o';
        }
        
        for (int i = 0; i < a + 1 - b % (a + 1); i++) {
            for (int j = 0; j < cnt; j++)
                res += 'x';

            if (i != a - b % (a + 1))    
                res += 'o';
        }
    } else {
        int cnt = b / 2;
        
        for (int i = 0; i < cnt; i++)
            res += 'x';
            
        for (int i = 0; i < a; i++) 
            res += 'o';
            
        for (int i = 0; i < b - cnt; i++)
            res += 'x';
    }
    
    long long ans = 0;
    long long cnt = 0;
    
    char last = 0;
    
    for (int i = 0; i < n; i++) {
        if (res[i] == last)
            cnt++;
        else {
            if (last == 'o')
                ans += cnt * cnt;
            else
                ans -= cnt * cnt;
                
            last = res[i];
            cnt = 1;
        }
    }
    
    if (last == 'o')
        ans += cnt * cnt;
    else
        ans -= cnt * cnt;
    
    cout << ans << endl << res;
    
    return 0;
}
    
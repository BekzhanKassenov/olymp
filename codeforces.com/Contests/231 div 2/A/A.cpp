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

    int a = 0, b = 0, c = 0;
    
    char ch;
    
    while ((ch = getchar()) == '|')
        a++;
        
    while ((ch = getchar()) == '|')
        b++;
        
    while ((ch = getchar()) == '|')
        c++;
        
    if (a + b == c) {
        for (int i = 0; i < a; i++)
            cout << '|';
        
        cout << '+';
        for (int i = 0; i < b; i++)
            cout << '|';
        
        cout << '=';
        for (int i = 0; i < c; i++)
            cout << '|';
            
    } else if (a + b == c + 2) {
        int new_a = a - 1, new_b = b;
        
        if (new_a <= 0) {
            new_a = a;
            new_b = b - 1;
            if (new_b <= 0) {
                cout << "Impossible";
                return 0;
            }
        }
        
        
        for (int i = 0; i < new_a; i++)
            cout << '|';
        cout << '+';
        
        for (int i = 0; i < new_b; i++)
            cout << '|';
            
        cout << '=';
        for (int i = 0; i < c + 1; i++)
            cout << '|';
    } else if (a + b + 2 == c) {
        for (int i = 0; i < a + 1; i++)
            cout << '|';
            
        cout << '+';
        for (int i = 0; i < b; i++)
            cout << '|';
            
        cout << '=';
        for (int i = 0; i < c - 1; i++)
            cout << '|';
    } else
        cout << "Impossible";
        
        
    return 0;
}

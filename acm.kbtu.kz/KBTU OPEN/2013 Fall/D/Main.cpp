/******************************************
**          Solution by NU #2            **
******************************************/

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define File "game"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T x) {
    return (x * x);
}
char now = 'F';
long long a, b;
void change(){
    if (now == 'F')
        now = 'S';
        else
            now = 'F';
}
int gcd(){
    if (a < b)
    swap(a, b);
    if (a == b){
        change();
        return 0;
    }
    if (a%b == 0){
        return 0;   
    }
    
    if (a-2*b < 0){
        a %= b;
        change();
        return 1;
    }
    return 0;
}
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> a >> b;
    
    while (gcd() == 1) {
    
    }
    
    if (now == 'F')
    cout << "First";
    else
    cout << "Second";
    return 0;
}
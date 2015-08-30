/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, t1, t2;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> t1 >> t2;

    bool f1 = false, f2 = false;
    int last = 0, t = 0, solved = 0, first = 0, second = 0;

    while (solved < n) {
        t++;
        f1 = f2 = false;

        if (t % t1 == 0) {
            solved++;
            f1 = true;
            last = t; 
            first++;
        }
        
        if (t % t2 == 0) {
            solved++;
            second++;
            f2 = true;
            last = t;        
        }
    }

    if (!f1) {
        solved++;
        first++;
        last = max (first * t1, second * t2);
    }
    if (!f2) {
        solved++;
        second++;
        last = max (first * t1, second * t2);
    }

    cout << solved << " " << last;
    

    return 0;
}

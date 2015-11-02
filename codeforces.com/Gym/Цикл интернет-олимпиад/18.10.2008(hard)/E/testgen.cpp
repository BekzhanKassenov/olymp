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

const int WORD_LENGTH = 50;

int main() {
    freopen("game.in", "w", stdout);
    
    srand(time(NULL));

    int n = 200;
    string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHJIKLMNOPQRSTUVWXYZ1234567890";

    cout << n << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < WORD_LENGTH; j++) {
            cout << a[rand() % a.length()];
        }    
        cout << endl;
    }

    return 0;
}
                     

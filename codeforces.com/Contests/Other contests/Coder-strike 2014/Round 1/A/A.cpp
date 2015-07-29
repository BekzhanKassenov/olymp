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

int n, k;
char s[110];
bool used[110];

void move_left() {
    while (k > 1) {
        if (!used[k]) {
            cout << "PRINT " << s[k] << endl;
            used[k] = true;
        }

        cout << "LEFT" << endl;
        k--;
    }

    if (!used[k]) {
        cout << "PRINT " << s[k] << endl;
        used[k] = true;
    } 
}

void move_right() {
    while (k < n) {
        if (!used[k]) {
            cout << "PRINT " << s[k] << endl;
            used[k] = true;
        }

        cout << "RIGHT" << endl;
        k++;
    }

    if (!used[k]) {
        cout << "PRINT " << s[k] << endl;
        used[k] = true;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);

    scanf("\n%s", s + 1);

    if (n - k > k - 1) {
        move_left();
        move_right();
    } else {
        move_right();
        move_left();
    }

    return 0;
}

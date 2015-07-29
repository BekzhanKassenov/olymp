/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int s[MAXN];
int x[MAXN][MAXN], pos;

int main() {
    cin >> n;

    while (true) {
        cin >> s[0];
        if (!s[0])
            break;

        for (int i = 1; i < n; i++)
            cin >> s[i];

        for (int i = 0; i < n; i++)
            if (s[i] < 0)
                x[i][pos] = 1;
            else
                x[i][pos] = 0;

        pos++;
    }

    for (int i = 0; i < n; i++) {
        cout << x[i][0] << '.';
        for (int j = 1; j < pos; j++)
            cout << x[i][j];

        cout << 1;

        cout << ' ';
    }

    cout << endl;

    for (int i = 0; i < pos; i++) {
        cout << 1;

        for (int j = 0; j < i; j++)
            cout << 0;

        cout << endl;
    }
    
    return 0;
}

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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char a, b;
bool table[5][5];

int num(char c) {
    if (c == 'R')
        return 0;

    if (c == 'G')
        return 1;

    if (c == 'B')
        return 2;

    if (c == 'Y')
        return 3;

    return 4;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("\n%c%c", &a, &b);
        table[num(a)][(int)b - '0' - 1] = true;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << table[i][j];
           cout << endl;
    }

    int ans = 0, cnt = 0;

    for (int i = 0; i < 5; i++) {
        bool flag = false;

        for (int j = 0; j < 5; j++)
            flag |= table[i][j];

        cnt += flag;
    }

    ans += cnt - 1;
    cnt = 0;


    for (int j = 0; j < 5; j++) {
        bool flag = false;

        for (int i = 0; i < 5; i++) {
            flag += table[i][j];
        }

        cnt += flag;
    }

    ans += cnt - 1;

    printf("%d\n", ans);
    
    return 0;
}

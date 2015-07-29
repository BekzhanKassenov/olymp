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

char s[110];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '8' || s[i] == '0') {
            puts("YES");
            printf("%c\n", s[i]);
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int num1 = s[i] - '0';
            int num2 = s[j] - '0';

            if ((num1 * 10 + num2) % 8 == 0) {
                puts("YES");
                printf("%c%c\n", s[i], s[j]);
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int num1 = s[i] - '0';
                int num2 = s[j] - '0';
                int num3 = s[k] - '0';

                if ((num1 * 100 + num2 * 10 + num3) % 8 == 0){
                    puts("YES");
                    printf("%c%c%c\n", s[i], s[j], s[k]);
                    return 0;
                }
            }
        }
    }

    puts("NO");

    return 0;
}

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

bool isvowel(char c) {
    return c == 'a' ||
           c == 'e' ||
           c == 'i' ||
           c == 'o' ||
           c == 'u';
}

int vowels(char s[]) {
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        if (isvowel(s[i])) {
            ans++;
        }
    }

    return ans;
}

char s[3][110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 3; i++) {
        gets(s[i]);
    }

    if (vowels(s[0]) == 5 && vowels(s[1]) == 7 && vowels(s[2]) == 5) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}

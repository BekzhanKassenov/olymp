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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, size;
char s[MAXN];
char t[MAXN];
char ans[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
        
    while (scanf("%d\n", &n) != -1 && n) {
        gets(s);
        size = 0;

        for (int i = 0; s[i]; i++) {
            if (isalpha(s[i]))
                t[size++] = toupper(s[i]);
        }

        int fpos = 0;
        int pos = 0;

        for (int i = 0; i < size; i++) {
            if (pos >= size) {
                fpos++;
                pos = fpos;
            }

            ans[pos] = t[i];
            pos += n;
        }

        ans[size] = '\0';
        puts(ans);
    }
    
    return 0;
}

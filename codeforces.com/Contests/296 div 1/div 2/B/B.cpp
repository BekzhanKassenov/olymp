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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int pos[26][26];
int n;
char s[MAXN];
char t[MAXN];
int dist;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    gets(s);
    gets(t);

    memset(pos, 255, sizeof pos);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'][t[i] - 'a'] = i;

        if (s[i] != t[i]) {
            dist++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (pos[t[i] - 'a'][s[i] - 'a'] != -1) {
                printf("%d\n%d %d", dist - 2, i + 1, pos[t[i] - 'a'][s[i] - 'a'] + 1);
                return 0; 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i] && pos[c - 'a'][s[i] - 'a'] != -1) {
                    printf("%d\n%d %d", dist - 1, i + 1, pos[c - 'a'][s[i] - 'a'] + 1);
                    return 0; 
                }
            }
        }
    }
    
    printf("%d\n-1 -1", dist);

    return 0;
}

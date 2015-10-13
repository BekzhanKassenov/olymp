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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
char s[MAXN], buf[MAXN];
char a[MAXN], b[MAXN];
set <string> Set;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        Set.clear();

        gets(s);

        while (gets(buf) != NULL) {
            if (strcmp(buf, "what does the fox say?") == 0) {
                break;
            }


            sscanf(buf, "%s goes %s", a, b);
            Set.insert(string(b));
        }
         
        char *ptr = s;
        char *last = s + strlen(s);

        while (sscanf(ptr, "%s", a) == 1 && ptr < last) {
            if (!Set.count(string(a))) {
                printf("%s ", a);
            }

            ptr += strlen(a) + 1;
        }
        puts("");
    }
    
    return 0;
}

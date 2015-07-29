/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "add-help"

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

char s[100];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n;
    scanf("%d", &n);
    gets(s);
    
    for (int i = 0; i < n; i++) {
        gets(s);
        
        if (strcmp(s, "P=NP") == 0) {
            puts("skipped");
        } else {
            int a, b;
            sscanf(s, "%d+%d", &a, &b);
            printf("%d\n", a + b);
        }
    }
    
    return 0;
}

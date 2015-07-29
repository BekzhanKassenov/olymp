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
#define File "odin"

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

char s[100010];

char para(char c, int b) {
    if (c == '(') {
        if (b == 1)
            return '{';

        return '[';
    } else if (c == ')') {
        if (b == 1)
            return '}';

        return ']';
    } else
        return c;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    gets(s);

    int bal = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            bal++;
            if (bal == 1 || bal == 2)
                s[i] = para(s[i], bal);

        } else if (s[i] == ')') {
            if (bal == 1 || bal == 2)
                s[i] = para(s[i], bal);
            bal--;
        }

                
    }

    puts(s);

    return 0;
}

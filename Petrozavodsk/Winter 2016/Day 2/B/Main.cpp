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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool used[10];
int len;
long long N, curN;
long long power10;
long long ansDist;
char s[20];
char cur[20];
char ans[20];

void go(int pos) {
    if (pos == len) {
        long long dist = min(abs(N - curN), power10 - abs(N - curN));
        if (dist > ansDist) {
            ansDist = dist;
            strcpy(ans, cur);
        }

        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!used[i]) {
            used[i] = true;
            cur[pos] = i + '0';
            curN *= 10;
            curN += i;

            go(pos + 1);

            curN /= 10;
            used[i] = false;
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);
    len = strlen(s);

    power10 = 1;
    for (int i = 0; s[i]; i++) {
        N *= 10;
        N += s[i] - '0';
        power10 *= 10;
    }

    go(0);

    puts(ans);
    
    return 0;
}

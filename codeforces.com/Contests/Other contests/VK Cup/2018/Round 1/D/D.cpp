/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
 
const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
 
template <typename T>
inline T sqr(T n) {
    return n * n;
}
 
char s[MAXN], t[MAXN];
int sumS[MAXN], sumT[MAXN];
int cntAS[MAXN], cntAT[MAXN];
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
 
    scanf("%s\n", s + 1);
    scanf("%s\n", t + 1);
 
    for (int i = 1; s[i]; i++) {
        sumS[i] = sumS[i - 1] + (s[i] == 'B' || s[i] == 'C');
    }
 
    for (int i = 1; t[i]; i++) {
        sumT[i] = sumT[i - 1] + (t[i] == 'B' || t[i] == 'C');
    }
 
    for (int i = 1; s[i]; i++) {
        if (s[i] == 'A') {
            cntAS[i] = cntAS[i - 1] + 1;
        } else {
            cntAS[i] = 0;
        }
    }
 
    for (int i = 1; t[i]; i++) {
        if (t[i] == 'A') {
            cntAT[i] = cntAT[i - 1] + 1;
        } else {
            cntAT[i] = 0;
        }
    }
 
    int n;
    scanf("%d", &n);
    while (n --> 0) {
        int ls, rs, lt, rt;
        scanf("%d%d%d%d", &ls, &rs, &lt, &rt);
 
        int sBC = sumS[rs] - sumS[ls - 1];
        int tBC = sumT[rt] - sumT[lt - 1];
 
        int sA = min(cntAS[rs], rs - ls + 1);
        int tA = min(cntAT[rt], rt - lt + 1);
 
        if (sA < tA) {
            putchar('0');
            continue;
        }

        if (sBC % 2 != tBC % 2) {
            putchar('0');
            continue;
        }

        if (sBC == tBC) {
            if (sA % 3 == tA % 3) {
                putchar('1');
            } else {
                putchar('0');
            }
            continue;
        }

        if (sBC != 0 && sBC < tBC) {
            if (sA >= tA) {
                putchar('1');
            } else {
                putchar('0');
            }
            continue;
        }

        if (sBC == 0 && tBC != 0) {
            if (sA > tA) {
                putchar('1');
            } else {
                putchar('0');
            }
            continue;
        }

        putchar('0');
    }
    putchar('\n');
 
    return 0;
}

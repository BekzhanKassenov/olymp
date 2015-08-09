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

char s[6][50] = {"+------------------------+",
                "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
                "|#.#.#.#.#.#.#.#.#.#.#.|.|",
                "|#.......................|",
                "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
                "+------------------------+"};

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int posi = 0, posj = 0;

    for (int i = 0; i < n; i++) {
        while (s[posi][posj] != '#') {
            posi++;

            if (posi == 6) {
                posj++;
                posi = 0;
            }
        }

        s[posi][posj] = 'O';
    }

    for (int i = 0; i < 6; i++)
        puts(s[i]);

    return 0;
}
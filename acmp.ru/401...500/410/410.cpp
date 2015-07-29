#include <iostream>
#include <cstdio>

using namespace std;

const int MAXPOS = 190;

int sum[MAXPOS][10][1010];
int par[MAXPOS][10][1010];
int parm[MAXPOS][10][1010];
int n, m;
int ans = -1, anspos, ansdig;
char res[MAXPOS + 1];

inline void update(int pos, int dig) {
    if (ans == -1 || ans > sum[pos][dig][n]) {
        ans = sum[pos][dig][n];
        anspos = pos;
        ansdig = dig;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    if (n % m == 0) {
        puts("0");
        return 0;
    }

    memset(sum, 255, sizeof sum);
    n = m - n % m;
    
    for (int dig = 1; dig < 10; dig++) {
        sum[0][dig][dig % m] = dig;

        if (dig % m == n)
            update(0, dig);
    }

    for (int pos = 0; pos < MAXPOS - 1; pos++) {
        for (int dig = 0; dig < 10; dig++) {
            for (int mod = 0; mod < m; mod++) {
                if (sum[pos][dig][mod] == -1)
                    continue;

                for (int next_dig = 0; next_dig < 10; next_dig++) {
                    int nmod = (mod * 10 + next_dig) % m;
                    int nsum = sum[pos][dig][mod] + next_dig;

                    int& nxt = sum[pos + 1][next_dig][nmod];

                    if (nxt == -1 || nxt > nsum) {
                        nxt = nsum;
                        par[pos + 1][next_dig][nmod] = dig;
                        parm[pos + 1][next_dig][nmod] = mod;
                    }

                    if (nmod == n)
                        update(pos + 1, next_dig);
                }
            }
        }
    }

    int mod = n;

    while (anspos >= 0) {
        res[anspos] = ansdig + '0';
        int tmod = mod;
        int tdig = ansdig;

        mod = parm[anspos][tdig][tmod];
        ansdig = par[anspos][tdig][tmod];
        anspos--;
    }

    printf("%s\n", res);

    return 0;
}

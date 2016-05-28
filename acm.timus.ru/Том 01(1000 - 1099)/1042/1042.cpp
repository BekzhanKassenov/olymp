#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

const int N = 260;

vector <bitset <N> > a;
int n;

void RREF(vector <bitset <N> >& a, vector <bool>& res) {
    int row = 0;
    for (int i = 0; i < n; i++) {
        int num = -1;
        for (int j = row; j < n; j++) {
            if (a[j][i] != 0) {
                num = j;
                break;
            }
        }

        if (num == -1) {
            continue;
        }

        swap(a[row], a[num]);
        swap(res[row], res[num]);

        for (int j = 0; j < n; j++) {
            if (row != j && a[j][i] != 0) {
                a[j] ^= a[row];
                res[j] = res[j] ^ res[row];
            }
        }

        row++;
    }

    for (int i = 0; i < n; i++) {
        bool empty = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                empty = false;
            }
        }

        if (empty && res[i]) {
            puts("No solution");
            exit(0);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    a.resize(n);

    for (int i = 0; i < n; i++) {
        int x;

        while (scanf("%d", &x) == 1 && x != -1) {
            a[x - 1][i] = 1;
        }
    }

    vector <bool> res(n, true);

    RREF(a, res);

    for (int i = 0; i < n; i++) {
        if (res[i]) {
            int num = -1;
            for (int j = 0; j < n; j++) {
                if (a[i][j]) {
                    num = j;
                    break;
                }
            }

            printf("%d ", num + 1);
        }
    }

    return 0;
}

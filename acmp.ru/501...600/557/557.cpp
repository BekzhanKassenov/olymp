#include <cstdio>
#include <memory.h>

using namespace std;

typedef long long ll;

const int maxn = 210;
const ll lim = 1e14;

ll *row, *temp, A[maxn][maxn], B[maxn][maxn];
int n, m, p;
int a, b;

void mult() {
    memset(temp, 0, n * sizeof (long long) );

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i] += row[j] * B[j][i];

            if (temp[i] > lim)
                temp[i] %= p;
        }

        temp[i] %= p;
    }

    ll *t = temp;
    temp = row;
    row = t;
}                                                          

ll read_int() {
    char c;
    ll res = 0;

    do {
        c = getchar();
    } while (c < '0' || c > '9');

    do {
        res *= 10;
        res += c - '0';
        
        c = getchar();
    } while (c >= '0' && c <= '9');
    
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &m, &n);
    scanf("%d%d%d", &a, &b, &p);
    a--, b--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = read_int();
    
    row = A[a];
    temp = A[maxn - 1];

    while (m --> 1) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                B[i][j] = read_int();

        mult();
    }

    printf("%I64d\n", row[b]);

    return 0;
}

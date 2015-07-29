/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "elegant"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1100 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int last;
vector <int> primes;
bool prime[MAXN];
long long a[50][50];

void build() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (prime[i]) {
            primes.push_back(i);
            if (1ll * i * i < MAXN) {
                for (int j = i * i; j < MAXN; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    build();
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int row = i;
        for (int col = 0; col < n; col++) {
            a[row][col] *= primes[last];
            row++;
            row %= n;
            cout << row + 1 << ' ' << col + 1 << endl;
        }
        cout << endl;
        last++;   
    }
    cout << endl << endl;

    for (int i = 0; i < n; i++) {
        int row = i;
        for (int col = n - 1; col >= 0; col--) {
            a[row][col] *= primes[last];
            cout << row + 1 << ' ' << col + 1 << endl;
            row--;
            row += n;
            row %= n;
        }
        cout << endl;
        last++;   
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%I64d ", a[i][j]);
        }
        puts("");
    }

    return 0;
}

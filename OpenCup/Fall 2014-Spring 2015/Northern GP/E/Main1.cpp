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
const int MAGICA = 1;

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

bool check() {
    set <int> Set;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Set.insert(a[i][j]);
        }
    }

    return (int)Set.size() < n * n;
}

int main() {
    //freopen(File".in", "r", stdin);
    //freopen(File".out", "w", stdout);

    build();
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }

    int rn[31];
    for (int i = 0; i < 31; i++) {
        rn[i] = i;
    }
    bool flip = true;
    int cnt = 0;
    while (check()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(stderr, "%I64d ", a[i][j]);
            }
            fprintf(stderr, "\n");
        }
        system("pause");
        if (flip) {
            for (int i = 0; i < n; i++) {
                int row = i;
                for (int col = 0; col < n; col++) {
                    a[row][col] *= primes[last];
                    row++;
                    row %= n;
                }
                cnt += n;
                if (cnt > n*n/2) {
                    last++;   
                    cnt = 0;
                }
            }
        }
        if (!check()) {
            break;
        }

        flip = flip^1;
        
        if (flip) {
            for (int i = 0; i < n; i++) {
                int row = i;
                for (int col = n - 1; col >= 0; col--) {
                    a[row][col] *= primes[last];
                    row--;
                    row += n;
                    row %= n;
                }
                cnt += n;
                if (cnt > n*n/2) {
                    last++;   
                    cnt = 0;
                }   
            }
        }
        if (!check()) {
            break;
        }

        for (int k = 0; k < MAGICA; k++) {
            random_shuffle(rn, rn + n);        
            for (int i = 0; i < n; i++) {
                a[rn[i]][i] *= primes[last];
            }
            cnt += n;
            if (cnt > n*n/2) {
                last++;   
                cnt = 0;
            }
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%I64d ", a[i][j]);
        }
        puts("");
    }

    return 0;
}

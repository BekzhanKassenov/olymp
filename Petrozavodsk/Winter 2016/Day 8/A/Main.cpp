/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 410;
const int MAXD = 413;
const int N = 3 * sizeof(int);

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
pair <int, int> t[MAXN];
bitset <MAXD> dp[MAXN][MAXD];
int par[MAXN][MAXD][MAXD];
int S[MAXN];
vector <int> vec[3];
int ans[3] = {0, 1, 2};

int compress(int a, int b) {
    return a * MAXD + b;
}

void uncomp(int num, int& a, int& b) {
    b = num % MAXD;
    a = num / MAXD;
}

void apply(int a[3], int b[3]) {
    static int temp[3];
    
    for (int i = 0; i < 3; i++) {
        temp[b[i]] = a[i];
    }

    memcpy(a, temp, N);
}

void restore(int pos, int d1, int d2) {
    //cerr << pos << ' ' << d1 << ' ' << d2 << endl;
    if (pos == 0) {
        return;
    }

    int pd1, pd2;
    uncomp(par[pos][d1][d2], pd1, pd2);

    int ca = (S[pos] - 2 * d1 - d2) / 3;
    int cb = ca + d1;
    int cc = cb + d2;

    int cur[3] = {ca, cb, cc};
    int arr[3];
    int pr[3];

    int posadd = -1;
    for (int i = 0; i < 3; i++) {
        arr[0] = (S[pos - 1] - 2 * pd1 - pd2) / 3;
        arr[1] = arr[0] + pd1;
        arr[2] = arr[1] + pd2;

        arr[i] += t[pos - 1].first;

        memcpy(pr, arr, N);

        sort(arr, arr + 3);

        if (memcmp(arr, cur, N) == 0) {
            posadd = i;
            break;
        }
    }

    int perm[3] = {0, 1, 2};
    int save[3];

    do {
        memcpy(save, cur, N);

        apply(cur, perm);

        if (memcmp(pr, cur, N) == 0) {
            break;
        }

        memcpy(cur, save, N);
    } while (next_permutation(perm, perm + 3));

    apply(ans, perm);
    vec[ans[posadd]].push_back(t[pos - 1].second);

    restore(pos - 1, pd1, pd2);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i].first);
        t[i].second = i + 1;
    }

    srand(time(NULL));
    random_shuffle(t, t + n);

    dp[0][0][0] = true;
    S[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int d1 = 0; d1 < MAXD; d1++) {
            for (int d2 = 0; d2 < MAXD; d2++) {

                int a = S[i] - 2 * d1 - d2;
                if (a % 3 != 0 || !dp[i][d1][d2]) {
                    continue;
                }

                a /= 3;
                int b = a + d1;
                int c = b + d2;
                int arr[3];

                for (int pos = 0; pos < 3; pos++) {
                    arr[0] = a;
                    arr[1] = b;
                    arr[2] = c;
                    arr[pos] += t[i].first;

                    sort(arr, arr + 3);
                    int nd1 = arr[1] - arr[0];
                    int nd2 = arr[2] - arr[1];

                    if (nd1 >= MAXD || nd2 >= MAXD) {
                        continue;
                    }

                    dp[i + 1][nd1][nd2] = true;
                    par[i + 1][nd1][nd2] = compress(d1, d2);
                }
            }
        }

        S[i + 1] = S[i] + t[i].first;
    }

    int mn = INF;
    int mni = -1, mnj = -1;
    for (int i = 0; i < MAXD; i++) {
        for (int j = 0; j < MAXD; j++) {
            if (dp[n][i][j] && i + j < mn) {
                mn = i + j;
                mni = i;
                mnj = j;
            }
        }
    }

    printf("%d\n", mn);
    
    restore(n, mni, mnj);

    for (int i = 0; i < 3; i++) {
        printf("%u ", vec[i].size());
        for (int num: vec[i]) {
            printf("%d ", num);
        }

        puts("");
    }

    return 0;
}

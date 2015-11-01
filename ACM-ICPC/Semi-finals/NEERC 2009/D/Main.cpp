/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "database"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int BASE = 131;
const int MAXN = 10010;
const int MAXM = 15;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
pair <int, int> a[MAXN][MAXM];
char buf[110];
int power[110];

pair <int, int> merge(const pair <int, int>& a, const pair <int, int>& b) {
    pair <int, int> result = a;
    result.first++;
    result.second = (1ll * result.second * BASE + ',') % MOD;
    result.first += b.first;
    result.second = (1ll * result.second * power[b.first]) % MOD;
    result.second += b.second;
    result.second %= MOD;

    return result;
}

void add(int row, char s[]) {
    int pos = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ',') {
            pos++;
        } else {
            a[row][pos].first++;
            a[row][pos].second = (1ll * a[row][pos].second * BASE) % MOD;
            a[row][pos].second += s[i];
            a[row][pos].second %= MOD;
        }   
    }
}

void print_ans(int col1, int col2) {
    puts("NO");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][col1] == a[j][col1] && a[i][col2] == a[j][col2]) {
                printf("%d %d\n", i + 1, j + 1);
                printf("%d %d\n", col1 + 1, col2 + 1);
                return;
            }
        }
    }
}   

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    power[0] = 1;
    for (int i = 1; i < 110; i++) {
        power[i] = (1ll * power[i - 1] * BASE) % MOD;
    }

    scanf("%d%d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(buf);
        add(i, buf);
    }

    for (int col1 = 0; col1 < m; col1++) {
        for (int col2 = col1 + 1; col2 < m; col2++) {
            vector <pair <int, int> > vec;

            for (int row = 0; row < n; row++) {
                vec.push_back(merge(a[row][col1], a[row][col2]));
            }

            sort(all(vec));

            for (size_t i = 0; i + 1 < vec.size(); i++) {
                if (vec[i] == vec[i + 1]) {
                    print_ans(col1, col2);
                    return 0;
                }
            }
        }
    }

    puts("YES");

    return 0;
}

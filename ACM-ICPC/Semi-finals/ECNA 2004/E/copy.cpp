/****************************************
**          Solution by NU #2          **
****************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

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

int n, r, m;
int v[15], c[15];
int ans[10];
int dp[22][1010];
int faces[22];
vector <int> labels[22];
vector <int> result;
map <vector <int>, vector <int> > Map;
bool found = false;

ostream& operator << (ostream& out, const vector <int>& vec) {
    out << '{';
    for (size_t i = 0; i + 1 < vec.size(); i++) {
        out << vec[i] << ", ";
    }

    out << vec.back() << '}';
    return out;
}

bool cmp(const vector <int>& a, const vector <int>& b) {
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }

    return false;
}

void go(int pos, int lim, vector <int>& vec) {
    if (pos == lim) {
        vector <int> res(lim);

        for (int i = 0; i < lim; i++) {
            res[i] = ans[i];
        }

        sort(all(res));
        if (!Map.count(vec) || cmp(res, Map[vec])) {
            Map[vec] = res;
        }
        
        return;
    }

    for (int label = 1; label <= 50; label++) {
        for (int j = 0; j < m; j++) {
            if (0 <= v[j] - label && v[j] - label < 1010) {
                vec[j] -= dp[n - 1][v[j] - label];
            }
        }

        ans[pos] = label;
        go(pos + 1, lim, vec);

        for (int j = 0; j < m; j++) {
            if (0 <= v[j] - label && v[j] - label < 1010) {
                vec[j] += dp[n - 1][v[j] - label];
            }
        }
    }
}

void go1(int pos, int lim, vector <int>& vec) {
    if (pos == lim) {
        if (Map.count(vec)) {
            vector <int> temp(r);

            for (int i = 0; i < r - lim; i++) {
                temp[i] = Map[vec][i];
            }

            for (int i = r - lim; i < r; i++) {
                temp[i] = ans[i];
            }

            sort(all(temp));
            if (cmp(temp, result)) {
                result = temp;
            }

            found = true;

            return;
        }
        return;
    }

    for (int label = 1; label <= 50; label++) {

        for (int j = 0; j < m; j++) {
            if (0 <= v[j] - label && v[j] - label < 1010) {
                vec[j] += dp[n - 1][v[j] - label];
            }
        }

        ans[pos + (r - lim)] = label;
        go1(pos + 1, lim, vec);

        for (int j = 0; j < m; j++) {
            if (0 <= v[j] - label && v[j] - label < 1010) {
                vec[j] -= dp[n - 1][v[j] - label];
            }
        }
    }
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    for (scanf("%d", &n); n != 0; scanf("%d", &n)) {
        Map.clear();
        memset(dp, 0, sizeof dp);
        found = false;

        for (int i = 0; i < n; i++) {
            scanf("%d", &faces[i]);
            labels[i].resize(faces[i]);

            for (int j = 0; j < faces[i]; j++) {
                scanf("%d", &labels[i][j]);
            }
        }

        bool has_greater = false;
        scanf("%d%d", &r, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &v[i], &c[i]);

            if (v[i] > MAXDP) {
                has_greater = true;
            }
        }

        if (has_greater) {
            puts("Impossible");
            continue;
        }
        
        result.assign(r, 50);
        for (int i = 0; i < faces[0]; i++) {
            dp[0][labels[0][i]] = 1;
        }

        for (int pos = 1; pos < n; pos++) {
            for (int sum = 0; sum < 1010; sum++) {
                for (int i = 0; i < faces[pos]; i++) {
                    if (sum - labels[pos][i] >= 0) {
                        dp[pos][sum] += dp[pos - 1][sum - labels[pos][i]];
                    }
                }
            }
        }

        vector <int> left(m);
        for (int i = 0; i < m; i++) {
            left[i] = c[i];
        }
        go(0, r / 2, left);
        
        left.assign(m, 0);
        go1(0, r - r / 2, left);
        
        if (!found) {
            printf("Impossible");
        } else {
            printf("Final die face values are ");
            for (int i = 0; i < r; i++) {
                printf("%d ", result[i]);
            }
        }

        puts("");
    }
    
    return 0;
}

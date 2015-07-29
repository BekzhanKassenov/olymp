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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN][MAXN];
char ans[MAXN][MAXN];
vector <pair <int, int> > bad, pos;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    
    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'o') {
                pos.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '.') {
                for (size_t k = 0; k < pos.size(); k++) {
                    int di = i - pos[k].first;
                    int dj = j - pos[k].second;

                    bad.push_back(make_pair(di, dj));
                }
            }
        }
    }

    sort(all(bad));
    bad.resize(unique(all(bad)) - bad.begin());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'x') {
                bool flag = false;
                for (size_t k = 0; k < pos.size(); k++) {
                    int di = i - pos[k].first;
                    int dj = j - pos[k].second;

                    if (!binary_search(all(bad), make_pair(di, dj))) {
                        flag = true;
                    }
                }

                if (!flag) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    puts("YES");

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            ans[i][j] = 'x';
        }
    }
    
    ans[n - 1][n - 1] = 'o';

    for (size_t i = 0; i < bad.size(); i++) {
        ans[n - 1 + bad[i].first][n - 1 + bad[i].second] = '.';
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        puts(ans[i]);
    }

    return 0;
}

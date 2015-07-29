#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 210;

int a[maxn][maxn], cur[maxn], l[maxn], r[maxn];
int n, m, k, ans;
int x, y, _x, _y;
vector <int> st;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 1;

    while (k --> 0) {
        scanf("%d%d%d%d", &x, &y, &_x, &_y);
        
        for (int i = max(x - 2, 0); i <= min(_x, n - 1); i++)
            for (int j = max(y - 2, 0); j <= min(_y, m - 1); j++)
                a[i][j] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cur[j] = a[i][j] * (cur[j] + 1);

        for (int j = 0; j < m; j++) {
            while (!st.empty() && cur[st.back()] >= cur[j]) {
                r[st.back()] = j - 1;
                st.pop_back();
            }

            l[j] = st.empty() ? 0 : (st.back() + 1);
            st.push_back(j);
        }

        while (!st.empty()) {
            r[st.back()] = m - 1;
            st.pop_back();
        }

        for (int j = 0; j < m; j++) {
            ans = max(ans, cur[j] * (r[j] - l[j] + 1));
        }
    }

    printf("%d\n", ans);

    return 0;
}   
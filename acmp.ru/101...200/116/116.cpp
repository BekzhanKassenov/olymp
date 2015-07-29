#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 1010;

char s[MAXN][MAXN];
int a[MAXN][MAXN];
int cur[MAXN], l[MAXN], r[MAXN];
int n, m, ans;
vector <int> st;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= n; i++) {
        gets(s[i]);

        for (int j = 0; j < m; j++)
            if (s[i][j] == '1')
                a[i][j + 1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1)
                cur[j]++;
            else
                cur[j] = 0; 
        }

        for (int j = 1; j <= m; j++) {
            while (!st.empty() && cur[st.top()] >= cur[j]) {
                r[st.top()] = j - 1;
                st.pop();
            }

            if (st.empty())
                l[j] = 1;
            else
                l[j] = st.top() + 1;    

            st.push(j);
        }

        while (!st.empty()) {
            r[st.top()] = m;
            st.pop();
        }

        for (int j = 1; j <= m; j++)
            ans = max(ans, (r[j] - l[j] + 1) * cur[j]);
    }

    printf("%d\n", ans);

    return 0;
}

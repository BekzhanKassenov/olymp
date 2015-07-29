#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;

int n, m, a[maxn], b[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    for (int i = 0; i < m; i++) {
        scanf("%d", b + i);
        b[i]--;
    }

    while (m--) {
        int ans = 0;

        int mnpos = b[m];

        for (int i = 0; i < n; i++) {
            if (a[(b[m] - i + n) % n] < a[mnpos]) {
                mnpos = (b[m] - i + n) % n;
            }
        }

        ans += a[mnpos] * n;
        int mn = a[mnpos];

        for (int i = 0; i < n; i++)
            a[i] -= mn;

        for (int i = 0; i < n; i++) {
            int pos = (b[m] - i + n) % n;
            
            if (a[pos]) {
                a[pos]--;
                ans++;
            } else
                break;
        }

        //cout << ans << ' ' << mnpos << endl;
        
        a[mnpos] = ans;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

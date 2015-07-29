/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int dp[100010];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    int n;

    scanf("%d", &n);

    vector <int> a(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int ans1 = 1;

    for (int i = 0; i < n; i++) {
        int ans = 0;

        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {   
                if (dp[j] + 1 > ans)
                    ans = dp[j] + 1;

                if (dp[a[i] / j] + 1 > ans)
                    ans = dp[a[i] / j] + 1;
            }
        }

        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {   
                dp[j] = ans;
                dp[a[i] / j] = ans;
            }
        }

        dp[a[i]] = max(ans, 1);

        ans1 = max(ans, ans1);
    }

    printf("%d\n", ans1);

    return 0;
}

/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>

int main()
{
    int l1;
    cin >> l1;
    vector <int> a(l1 + 1);
    for (int i = 1; i <= l1; i++)
        cin >> a[i];

    int l2;
    cin >> l2;
    vector <int> b(l2 + 1);
    for (int i = 1; i <= l2; i++)
        cin >> b[i];

    int l3;
    cin >> l3;
    vector <int> c(l3 + 1);
    for (int i = 1; i <= l3; i++)
        cin >> c[i];

    vector <vector <vector <int> > > dp(l1 + 1, vector <vector <int> > (l2 + 1, vector <int> (l3 + 1)));

    for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
                {
                    for (int k = 1; k <= l3; k++)
                        {
                            if (a[i] == b[j] && a[i] == c[k])
                                dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                            else
                                dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                        }
                }
        }
  

    VI ans;

    cout << dp[l1][l2][l3] << endl;

    while (l1 != 0 && l2 != 0 && l3 != 0)
        {
            if (a[l1] == b[l2] && b[l2] == c[l3])
                {
                    ans.PB(a[l1]);
                    l1--;
                    l2--;
                    l3--;
                }
            else
                {
                    if (dp[l1][l2][l3] == dp[l1 - 1][l2][l3])
                        {
                            l1--;
                            continue;
                        }
                    if (dp[l1][l2][l3] == dp[l1][l2 - 1][l3])
                        {
                            l2--;
                            continue;
                        }
                    if (dp[l1][l2][l3] == dp[l1][l2][l3 - 1])
                        {
                            l3--;
                            continue;
                        }
                }
        }
    
    
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    
    return 0;

}

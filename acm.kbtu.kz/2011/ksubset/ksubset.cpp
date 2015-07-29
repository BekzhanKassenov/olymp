#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) x * x
#define SZ() size()
#define VI vector <int>
#define MP make_pair
#define PB push_back
#define F first 
#define S second

using namespace std;

vector <int> a,b;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("ksubset.in","r",stdin);
    freopen("ksubset.out","w",stdout);
    #endif
    int n, m;
    cin >> n >> m;

    a.resize(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    b.resize(m);

    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector <pair <int, int> > dp;
    
    dp.reserve(1 << n);

    for (int mask = 1; mask < (1 << n); mask++)
        {
            int temp = 0;
            for (int i = 0; i < n; i++)
                if ((mask & (1 << i)) > 0)
                    temp += a[i];
            int temp1 = 0;
            for (int i = 0; i < m; i++)
                if (temp == b[i])
                    temp1 += (1 << i);
            if (temp1 != 0)
                dp.PB(MP(mask, temp1));
        }
   int ans1 = (1 << n) - 1;
   int ans2 = (1 << m) - 1;
   vector <pair <int, int> > q = dp;
   while (!q.empty())
    {
        pair <int, int> k = q[0];
        q.erase(q.begin());
        if (k.F == ans1 && k.S == ans2)
            {
                cout << "YES";
                return 0;
            }
        for (int i = 0; i < q.SZ(); i++)
            if (((k.F & q[i].F) == 0) && ((k.S & q[i].S) == 0))
                q.PB(MP((k.F | q[i].F), (k.S | q[i].S)));
    }
   cout << "NO";
   return 0;
}

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
#define INF 350
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int n;

vector <int> a;

vector <vector <vector <bool> > > dp, calced;

bool dfs(int a, int b, int c)
{
    //cout << who << ' ' << a << ' ' << b << ' ' << c << endl;

    if (a == 0)
        {
            if (b == 0)
                {
                    if (c == 0)
                        return false;
                    else
                        if (c == INF)
                            return false;
                }
            else
                if (b == INF && c == INF)
                    return false;
        }

    if (calced[a][b][c])
        return dp[a][b][c];

    calced[a][b][c] = true;

    bool flag = false;

    if (a != 0)
        {
            for (int i = 1; i <= a; i++)
                flag = flag | (!dfs(a - i, b, c)); 
        }

    if (b != INF)
        {
            for (int i = 1; i <= b; i++)
                flag = flag | (!dfs(a, b - i, c));
        }

    if (c != INF)
        {
            for (int i = 1; i <= c; i++)
                flag = flag | (!dfs(a, b, c - i)); 
        }


    int mn = min(min(a, b), c);

    for (int i = 1; i <= mn; i++)    
        {
            int ta = a - i;
            
            int tb = INF, tc = INF;
            
            if (b != INF)
                tb = b - i;

            if (c != INF)
                tc = c - i;

            flag = flag | (!dfs(ta, tb, tc));  
        }

    return (dp[a][b][c] = flag);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    cin >> n;

    a.resize(n);

    dp.resize(400, vector <vector <bool> > (400, vector <bool> (400, false)));

    calced = dp;

    for (int i = 0; i < n; i++)
        cin >> a[i];    

    int ta = a[0], tb = INF, tc = INF;

    if (n >= 2)
        tb = a[1];

    if (n == 3)
        tc = a[2];

    if (dfs(ta, tb, tc))
        cout << "BitLGM";
    else
        cout << "BitAryo";

    return 0;
}
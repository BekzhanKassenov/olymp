#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

#define abs (x) (x < 0)?(-x):(x)
#define sqr(q) (q)*(q)
#define inf 1000000000

int main()
{
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    int ans , ans1, ans2;
    if (x == 0)
        {
            cout << "YES";
            return 0;
        }
    for (int i = 1; i <= t; ++i)
         for (int j = 1; j <= t; ++j)
      {
       ans1 = a - ((i - 1) * da);
       ans = a - ((i - 1) * da) + b - ((j - 1) * db);
       ans2 = b - ((j - 1) * db);

       if (ans == x || ans1 == x || ans2 == x)
       {
        puts ("YES");
        return 0;
       }
      }           
    cout << "NO";
    return 0;
}
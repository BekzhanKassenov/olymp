/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

#define sqr(x) (x) * (x)
#define INF 1000000000
#define EPS 10E-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n;
   cin >> n;
   VI a(n + 1);
   int x;
   for (int i = 1; i <= n; i++)    
       {
           cin >> x;
           a[x] = i;
       }
   
   VI b(n + 1);
   for (int i = 1; i <= n; i++)
       {
           cin >> x;
           b[x] = i;
       }

   int mn = n;
   
   for (int i = 1; i <= n; i++)
   	mn = min(abs(a[i] - b[i]), mn);	
   
   cout << mn << endl;
    
   for (int j = 1; j < n; j++)    
   	{
	      mn = n;
         for (int i = 1; i <= n; i++)
   	      {
      	      b[i] ++;
               if (b[i] > n)
         	      b[i] = 1;
                  mn = min(mn, abs(b[i] - a[i]));
            }
         cout << mn << endl;    
     	}
	return 0;
}

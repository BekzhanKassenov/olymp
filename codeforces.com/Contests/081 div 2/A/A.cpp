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
#define ll long long 
#define ull unsigned long long

int main()
{
	#ifndef ONLINE_JUDGE
       freopen("in", "r", stdin);
   #endif

   int n, m;

   double k;
   
   cin >> n >> m >> k;

   vector <pair <string, int> > a;

   pair <string, int> tmp;

   set <string> used;

   int ans = 0;
   
   for (int i = 0; i < n; i++)
    	{
    		cin >> tmp.F >> tmp.S;
    		tmp.S = (int) (tmp.S * k);
    		if (tmp.S >= 100)
    			{
    				a.push_back(tmp);
    				used.insert(tmp.F);
    				ans++;
    			}
    	}

   for (int i = n; i < n + m; i++)
   	{
   		cin >> tmp.F;
   		tmp.S = 0;

   		if (used.find(tmp.F) == used.end())
   			{
   				a.push_back(tmp);
   				used.insert(tmp.F);
   				ans++;
   			}
   	}

   cout << ans << endl;

	sort(a.begin(), a.end());	

   for (int i = 0; i < ans; i++)
   	cout << a[i].F << ' ' << a[i].S << endl;

   return 0;
}

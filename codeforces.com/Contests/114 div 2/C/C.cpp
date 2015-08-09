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

#define PII pair <double, double>
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

   int n;

   double av, d;

   scanf("%d%lf%lf", &n, &av, &d);

   vector <PII> a(n);

	for (int i = 0; i < n; i++)
    	scanf("%lf%lf", &a[i].F, &a[i].S);

   vector <double> t(n);

   for (int i = 0; i < n; i++)
   	{
   		t[i] = a[i].F;
   		double tmp = 0;

   		tmp += a[i].S / av;

   		if ((av * tmp * tmp) > d * 2)
   			{
   				t[i] += sqrt((2 * d) / av);
   				continue;
   			}
   		else
   			{
   				t[i] += tmp;
   				tmp = d - av * tmp * tmp / 2;
   				t[i] += tmp / a[i].S;
   			}

   	}

   for (int i = 1; i < n; i++)
   	{
   		t[i] = max(t[i], t[i - 1]);
   	}

   for (int i = 0; i < n; i++)
   	printf("%.6lf\n", t[i]);
   
   return 0;
}
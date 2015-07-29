/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS 1e-9

struct point
{
    double x, y;

    point() {}

    point(double x, double y) : x(x), y(y) {}
};

int cmp(double a, double b)
{
    if (fabs(a - b) < EPS)
        return 0;

    if (a - b > EPS)
        return 1;

    return -1;
}

bool operator < (pair <double, bool> a, pair <double, bool> b)
{
    int k = cmp(a.F, b.F);

    if (k == 0)
        {
            if (a.S == true)
                return true;

            return false;
        }

    if (k == -1)
        return true;

    return false;
}

int main()
{
   #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
   #endif

   double x, y, _x, _y;

   int n;

   cin >> n;

   vector <pair <double, bool> > a;

   a.reserve(2 * n);

   for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> _x >> _y;

        double pol1 = atan2(x, y);

        double pol2 = atan2(_x, _y);

        if (x * _y - y * _x > 0)
            {
                a.push_back(MP(pol1, true));

                a.push_back(MP(pol2, false));
            }

        else
            {
                a.push_back(MP(pol1, false));

                a.push_back(MP(pol2, true));    
            }
    }

   sort(a.begin(), a.end());

    return 0;
}

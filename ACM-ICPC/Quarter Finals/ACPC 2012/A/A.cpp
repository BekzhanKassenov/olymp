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
#define EPS

int main()
{
   #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
   #endif

   int c, v;

   cin >> c >> v;

   vector <vector <int> > a(v, vector <int> (c));

   for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < c; j++)
            {
                cin >> a[i][j];
                a[i][j]--;
            }
    }

   vector <PII> votes(c);

   int cnt = (v >> 1) + 1;

   for (int i = 0; i < c; i++)
    votes[i].S = i; 

   for (int i = 0; i < v; i++)
    votes[a[i][0]].F++;

   for (int i = 0; i < c; i++)
    {
        if (votes[i].F >= cnt)
            {
                cout << i + 1 << ' ' << 1;
                return 0;
            }
    }


   sort(votes.rbegin(), votes.rend());

    votes[0].F = 0;
    votes[1].F = 0;

    for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < c; j++)
                {
                    if (a[i][j] == votes[0].S)
                        {
                            votes[0].F++;
                            break;
                        }
                    if (a[i][j] == votes[1].S)
                        {
                            votes[1].F++;
                            break;
                        }
                }
        }

    if (votes[0].F > votes[1].F)
        cout << votes[0].S + 1;

    else
        cout << votes[1].S + 1;

    cout << ' ' << 2;
    return 0;
}

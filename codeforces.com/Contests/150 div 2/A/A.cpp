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

    int n, k;

    cin >> n >> k;

    VI a(k);

    for (int i = 0; i < k; i++)
    	{
    		cin >> a[i];
    	}

    vector <bool> used(n * k + 20);

    vector <vector <int> > tmp(k);

    for (int i = 0; i < k; i++)
    	{
    		tmp[i].push_back(a[i]);
    		used[a[i]] = true;
    	}

    int j = 1;

    for (int i = 0; i < k; i++)
    	{
    		int x = n - 1;

    		while (x--)
    			{
    				while (used[j])
    					j++;

    				used[j] = true;

    				tmp[i].push_back(j++);
    				
    			}
    	}

    for (int i = 0; i < k; i++)
    	{
    		for (int q = 0; q < n; q++)
    			cout << tmp[i][q] << ' ';

    		cout << endl;	
    	}
    return 0;
}

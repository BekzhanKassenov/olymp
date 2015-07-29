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
#define ull unsigned long long
#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector <int> a(n + 1);

	vector <int> yes(n + 1), no(n + 1);

	int cntn = 0;

	for (int i = 1; i <= n; i++)
		{
			cin >> a[i];

			if (a[i] > 0)
				{
					yes[a[i]]++;
				}
			else
				{
					cntn++;
					no[abs(a[i])]++;
				}	
	  	}

	 set <int> pod;

	 for (int i = 1; i <= n; i++)
	 	{
	 		int tru = yes[i] + cntn - no[i];

	 		if (tru == m)
	 			pod.insert(i);
	 	}

	int cnt = pod.size();

	for (int i = 1; i <= n; i++)
		{
			if (a[i] > 0)
	 			{
	 				if (pod.find(a[i]) != pod.end())
	 					{
	 						if (cnt == 1)
	 							cout << "Truth" << endl;
	 						else
	 							cout << "Not defined" << endl;
	 					}
	 				else
	 					cout << "Lie" << endl;	
	 			}
	 		else
	 			{
	 				if (pod.find(abs(a[i])) != pod.end())
	 					{
	 						if (cnt == 1)
	 							cout << "Lie" << endl;
	 						else
	 							cout << "Not defined" << endl;	
	 					}
	 				else
	 					cout << "Truth" << endl;	
	 			}	
	 	}

	return 0;
}

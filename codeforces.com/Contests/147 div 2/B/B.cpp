/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define PIS pair <int, string>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define LL long long
#define ULL unsigned long long

struct sw
{
 	int i1, j1, i2, j2;
};

sw ME(int x, int y, int z, int p)
{
	sw ans;
 	ans.i1 = x + 1;
 	ans.j1 = y + 1;
 	ans.i2 = z + 1;
 	ans.j2 = p + 1;
 	return ans;   
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	vector <sw> ans;

	int n;
	
	cin >> n;

	vector <int> c(n);

	for (int i = 0; i < n; i++)
		cin >> c[i];

	vector <vector <int> > a(n);

	for (int i = 0; i < n; i++)
		{
			a[i].resize(c[i]);

			for (int j = 0; j < c[i]; j++)
				cin >> a[i][j];
		}

	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < c[i]; j++)
			{
				cnt++;

				if (cnt == a[i][j])
					continue;

				bool flag = false;

				for (int i1 = 0; i1 < n; i1++)
					{
						if (flag)
							break;
						
						for (int j1 = 0; j1 < c[i1]; j1++)
							if (a[i1][j1] == cnt)
								{
									ans.push_back(ME(i, j, i1, j1));
									swap(a[i][j], a[i1][j1]);
									flag = true;
									break;
								}
					}
							
			}

	cout << ans.size() << endl;

	for (int i = 0; i < (int) ans.size(); i++)
		{
			cout << ans[i].i1 << ' ' << ans[i].j1 << ' ' << ans[i].i2 << ' ' << ans[i].j2 << endl;
		}

	return 0;
}

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
	
	int n1, n2, m1, m2;
	cin >> n1 >> m1;

	vector <vector <int> > a(n1, vector <int> (m1));

	for (int i = 0; i < n1; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < m1; j++)
				a[i][j] = (s[j] - '0'); 
		}

	cin >> n2 >> m2;	

	vector <vector <int> > b(n2, vector <int> (m2));

	for (int i = 0; i < n2; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < m2; j++)
				b[i][j] = (s[j] - '0'); 
		}


	int a1 = -110, a2 = -110, c = 0;

	for (int x = -110; x < 110; x++)
		{
			for (int y = -110; y < 110; y++)
				{
					int tmp = 0;

					for (int i = 0; i < n1; i++)
						for (int j = 0; j < m1; j++)
							if (i + x < n2 && i + x >= 0)
								if (j + y < m2 && j + y >= 0)
									tmp += (a[i][j] * b[i + x][j + y]);

					if (tmp > c)
						{
							c = tmp;
							a1 = x;
							a2 = y;
						}
				}
		}

	cout << a1 <<  ' ' << a2;
	return 0;
}

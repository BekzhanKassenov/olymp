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
#define EPS 1e-1
#define File "vampire" 

bool used[1000000];

bool check(int a, int b, int c)
{
	int cf[10] = {0};

	while (a)
		{
			cf[a % 10] ++;
			a /= 10;
		}

	while (b)
		{
			cf[b % 10] ++;
			b /= 10;
		}

	while (c)
		{
			cf[c % 10] --;
			c /= 10;
		}	

	for (int i = 0; i < 10; i++)
		if (cf[i])
			return false;

	return true;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int k, n;

	cin >> k >> n;

	if (n == 4)
		{
			for (int i = 10; i <= 99; i++)
				for (int j = 10; j <= 99; j++)
					{
						if (check(i, j, i * j) && !used[i * j] && i * j > 1000)
							{
								cout << i * j << '=' << i << 'x' << j << endl;
								used[i * j] = true;
								k--;
								if (!k)
									return 0;
							}
					}
		}

	vector <int> f, s;

	bool flag = true;

	for (int i = 100; i < 1000 && flag; i++)
		for (int j = i; j < 1000 && flag; j++)
			{
				if (check(i, j, i * j) && !used[i * j] && i * j > 100000)
					{
						used[i * j] = true;
						f.push_back(i);
						s.push_back(j);
						k--;
						if (!k)
							flag = false;
					}
			}

	string s1, s2;

	//if (n != 6)
	//	{
			for (int i = 3; i < (n >> 1); i++)
				s2 += "0";
		
			for (int i = 6; i < n; i++)
				s1 += "0";

	//	}
	for (int i = 0; i < (int) f.size(); i++)
		cout << f[i] * s[i] << s1 << '=' << f[i] << s2 << 'x' << s[i] << s2 << endl;

	return 0;
}

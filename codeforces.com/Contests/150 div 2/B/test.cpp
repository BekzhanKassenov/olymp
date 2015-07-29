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

int len;

int m;

int lg(int n)
{
	int ans = 0;
	while (n)
		{
			n /= 10;
			ans++;
		}

	return ans;
}

int str_to_int(string s)
{
	int ans = 0;

	int l = s.length();

	for (int i = 0; i < l; i++)
		{
			ans *= 10;
			ans += s[i] - '0';
		}

	return ans;
}

bool check(int x, int y, int mask, int& q)
{
	string s;

	while (mask)
		{
			if (mask & 1)
				s += x + '0';
			else
				s += y + '0';

			mask >>= 1;	
		}

	reverse(s.begin(), s.end());

	if (s[0] == '0')
		return false;

	q = str_to_int(s);

	if (q <= m)
		return true;

  	return false;

}

int fast()
{
	 len = lg(m);

	 map <int, bool> used;

    int ans = 0;

    int tmp;

    for (int x = 0; x <= 9; x++)
    	{
    		for (int y = 0; y <= 9; y++)
    			{
    				for (int mask = 1; mask < (1 << len); mask++)
    					{
    						if (check(x, y, mask, tmp))
    							{
    								if (!used[tmp])
    									{
    										ans++;
    										used[tmp] = true;
    									}
    							}
    					}
    			}
    	}

    return ans;
}

bool check(int n)
{
	int a = -1, b = -1;

	while (n)
		{
			int tmp = n % 10;

			if (a == -1)
				{
					a = tmp;
				}
			else
				if (b == -1 && tmp != a)
					{
						b = tmp;
					}

				else
					{
						if (tmp != a && tmp != b)
							return false;
					}
			 n /= 10;
		}
	return true;	
}


int slow()
{
	int ans = 0;

	for (int i = 1; i <= m; i++)
		if (check(i))
			ans++;

	return ans;
}

int main()
{
  	freopen("out", "w", stdout);
  	for (m = 100000; m <= 1000000;m++)  	
    	{
    		if (slow() != fast())
    			{
    				cout << "ERROR " << m << ' ' << slow() << ' ' << fast() << endl;
    				return 0;
    			}
    	}

    return 0;
}

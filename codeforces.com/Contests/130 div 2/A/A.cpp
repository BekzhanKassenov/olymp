/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) x * x
#define SZ size
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define INF 2000000000 
#define EPS 10E-9

int main()
{
	//freopen("in","r",stdin);
	string s;
	cin >> s;
	string ans;
	int i = 0;
	int len = s.length();
	while (i < len)
		{
			if (s.substr(i, 3)=="WUB")
				{
					i += 3;
					if (!ans.empty())
						{
							cout << ans << ' ';
							ans.clear();
						}
				}
			else
				{
					ans += s[i];
					i++;
			   }

		}
	cout << ans;
	return 0;
}

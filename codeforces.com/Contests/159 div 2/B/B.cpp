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

PII try_make(int a, int b)
{
	bool flag1 = false, flag2 = true;

	a--;

	PII ans(0, 0);

	string s = "a";

	for (;a || b;)
		{
			if (flag1)
				{
					if (a == 0)
						{
							b--;
							s += 'b';
							flag2 = false;
						}
					else
						if (b == 0)
							{
								a--;

								s += 'a';

								flag2 = true;
							}
						else
							{
								if (flag2)
									{
										a--;
										s += 'a';
								  	}
								else
									{
										b--;
										s += 'b';
									}
							}  
				}
			else
				{
					if (a == 0)
						{
							b--;

							s += 'b';

							flag2 = false;
						}
					else
						if (b == 0)
							{
								a--;
								
								s += 'a';

								flag2 = true;
							}
						else
							{
								if (!flag2)
									{
										a--;
										s += 'a';
									}
								else
									{
										b--;
										s += 'b';
									}

								flag2 ^= 1;
							}  
				}

		  flag1 ^= 1;
		}

	for (int i = 1; i < (int) s.length(); i++)
		if (s[i] == s[i - 1])
			ans.F++;
		else
			ans.S++;
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	PII a = try_make(n, m), b = try_make(m, n), ans;

	if (a.F > b.F)
		ans = a;
	else
		if (a.S < b.S)
			ans = a;
		else
			ans = b;

	cout << ans.F << ' ' << ans.S;

	return 0;
}

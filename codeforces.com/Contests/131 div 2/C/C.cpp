#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector <bool> can;
vector <set <int> > g;
vector <int> kmp;

int n;

void init()
{
	g.resize(n);
	can.assign(n, false);
	kmp.resize(n);
}

int check(int k)
{
	int ans = 5;
	cout << k << ':' << ' ';
	vector <bool> c = can, pr(n, false);
	vector <set <int> > a = g;
	for (;;)
		{
			bool q = false;
			for(;;)
				{
					for (int i = 0; i < n; i++)
						{
							q = false;
							if ((c[i]) && (!pr[i]) && (kmp[i] == k))
								{
									cout << i + 1 << ' ';
									pr[i] = true;
									for (int j = 0; j < n; j++)
										{
											q = q | a[j].erase(i);
											if (a[j].empty())
												c[j] = true;
										}
								
								}
					      if (!q)
					 			break;
						}
					if (!q)
					 	break;	
				}
			bool any = true;
			for (int i = 0; i < n; i++)
				if (!pr[i])
					any = false;
			if (any)
				{
					cout << ans << endl;
					return ans;
				}
 
			k++;
			if (k == 4)
				k = 1;
			ans++;
		}
	}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	#endif
	cin >> n;
	init();
	if (n == 1)
		{
			cout << 1;
			return 0;
		}
	for (int i = 0; i < n; i++)
		cin >> kmp[i];
   for (int i = 0; i < n; i++)
   	{
   		int k;
   		cin >> k;
   		if (k == 0)
   			can[i] = true;
   		int v;
   		for (int j = 0; j < k; j++)
   			{
   				cin >> v;
   				g[i].insert(--v);
   			}
   	}

   int ans = 100000000;
   for (int i = 1; i <= 3; i++)
   	ans = min (ans, check(i));
   cout << ans;
   return 0;
}

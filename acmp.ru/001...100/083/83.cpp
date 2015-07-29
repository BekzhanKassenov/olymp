#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,m;

vector <vector <bool> > can;

int bit (int mask, int n)
{
	if ((mask & (1 << n)) > 0)
		return 1;
	else
		return 0;
}

void make()
{
	for (int mask1 = 0; mask1 < (1 << n); mask1++)
		for (int mask2 = 0; mask2 < (1 << n); mask2++)
			{
				for (int i = 0; i < n - 1; i++)
					{
						int a = bit (mask1, i);
						int b = bit (mask1,i + 1);
						int c = bit (mask2, i);
						int d = bit (mask2,i + 1);
						if (a + b + c + d == 0 || a + b + c + d == 4)
							{
								can[mask1][mask2] = false;
								can[mask2][mask1] = false;
							}
					}
			}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
   
   cin >> n >> m;

   if (n > m)
   	swap(n,m);

   can.resize(1 << n);
   for (int i = 0; i < (1 << n); i++)
   	can[i].assign(1 << n,true);


   make();

   vector <vector <int> > dp (1 << n, vector <int> (m + 1,0));

   for (int mask = 0; mask < (1 << n); mask++)
   	dp[mask][0] = 1;

   for (int i = 1; i < m; i++)
   	{
   		for (int mask1 = 0; mask1 < (1 << n); mask1++)
   			for (int mask2 = 0; mask2 < (1 << n); mask2++)
   				if (can[mask1][mask2])
   					dp[mask1][i] += dp[mask2][i-1];
   	}

   int ans = 0;
   
   for (int mask = 0; mask < (1 << n); mask++)
   	ans += dp[mask][m - 1];

   cout << ans;
   return 0;
}

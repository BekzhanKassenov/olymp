#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int n, m;

void right_turn(PII &a)
{
	if (a == MP(0, 1))
		{
			a.F = 1, a.S = 0;
			return;
		}

	if (a == MP(1, 0))
		{
			a.F = 0, a.S = -1;
			return;
		}

	if (a == MP(0, -1))
		{
			a.F = -1, a.S = 0;
			return;
		}

	if (a == MP(-1, 0))
		{
			a.F = 0, a.S = 1;
			return;
		}
}

vector <vector <int> > g;

bool ok(PII a)
{
	if (a.F >= 0 && a.F < n)
		if (a.S >= 0 && a.S < m)
			if (!g[a.F][a.S])
				return true;

 	return false;
}

PII operator + (PII a, PII b)
{
	a.F += b.F;
	a.S += b.S;
	return a;
}

int main()
{
   #ifndef ONLINE_JUDGE
   	freopen("in", "r", stdin);
   #endif

   cin >> n >> m;

   g.assign(n + 1, vector <int> (m + 1));

   PII np = MP(0, 1);

   PII now = MP(0, 0);

   bool flag = false;

   int ans = 1;

   g[now.F][now.S] = 1;

   for (;;)
   	{
   		PII tmp = now + np;

   		//cout << now.F << ' ' << now.S << endl;

   		if (ok(tmp))
   			{
   				ans += flag;
   				now = tmp;
   				flag = false;
   				g[now.F][now.S] = 1;
   			}
   		else
   			{
   				if (flag)
   					break;
   				else
   					{
   						right_turn(np);
   						flag = true;
   					}
   	  		}
   	}

   cout << ans - 1;	

   return 0;
}

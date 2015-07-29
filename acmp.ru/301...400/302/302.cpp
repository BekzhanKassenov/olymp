#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

#define PII pair <double, double>
#define MP make_pair
#define F first
#define S second

double sqr(double x)
{
	return x * x;
}

double dst(PII a, PII b)
{
	return (sqr(a.F - b.F) + (sqr(a.S - b.S)));
}

vector <PII> a;

int n;

vector <bool> used;

void dfs(int v, double c)
{
	used[v] = true;

	for (int i = 0; i < n; i++)
		if (dst(a[v], a[i]) <= c && !used[i])
			dfs(i, c);
}

bool check(double c)
{
	used.assign(n, false);

	int ans = 0;

	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				dfs(i, c);
				ans++;
			}
	if (ans > 1)
		return false;

	return true;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	
	cin >> n;
	a.resize(n);


	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	set <double> q;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					if (dst(a[i], a[j]) != 0)
						q.insert(dst(a[i], a[j]));
				}
		}

 	vector <double> d(q.begin(), q.end());

	int l = 0, r = (int)d.size() - 1;

	double ans;

	if (check(d[0]))
		{
			ans = d[0];
			goto END;
		}	

	else
		ans = d[r];

	while (l < r)
		{
			int m = (l + r) / 2;

			if (check(d[m]))
				{
					ans = min(ans, d[m]);
					r = m;
				}
			else
				l = m + 1;
		}	

	END:printf("%.2lf", sqrt(double(ans)));
	return 0;
		
}

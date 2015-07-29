#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> a,f;
vector <vector <int> > dp;

int n;

void add(int val, int p)
{	
	for (int i = p; i < n; i = i | (i + 1))
		f[i] += val;
}

int sum (int p)
{
	int ans = 0;
	for (int i = p; i >= 0; i = (i & (i + 1)) - 1)
		ans += f[i];
	return ans; 
}

int sum (int l, int r)
{
	return sum(r) - sum (l - 1);
}

int solve(int l, int r)
{
	if (l == r)
		return dp[l][r];
	if (r - l == 1)
		{
			return max(a[r], a[l]);
		}
	int v1, v2;
	if (dp[l + 1][r] == -1)
		v1 = solve (l + 1, r);
	else
		v1 = dp[l + 1][r];
	
	if (dp[l][r - 1] == -1)
		v2 = solve(l, r - 1);
	else
		v2 = dp[l][r - 1];
	
	dp[l][r] = max (sum(l, r - 1) - v2 + a[r] , sum(l + 1,r) - v1 + a[l]);
	
	return dp[l][r];	
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	a.resize(n);
	f.resize(n);

	dp.resize(n);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			dp[i].assign(n, -1);
			add(a[i],i);
	   }
	
	for (int i = 0; i < n; ++i)
		dp[i][i] = a[i];

	dp[0][n-1] = solve(0, n - 1);
	
	int val = dp[0][n-1] - sum(0, n - 1) + dp[0][n-1];
	//cout << val << ' ';
	if (val == 0)
			cout << 0;
	if (val < 0)	
		cout << 2;
	if (val > 0)
		cout << 1;
	return 0;
}

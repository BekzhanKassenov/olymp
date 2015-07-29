#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void print(const vector <int> &a)
{
	for (int i = a.size() - 1; i >= 0; i--)
		cout << a[i];

	cout << endl;
}

vector <int> operator + (const vector <int> &a, const vector <int> &b)
{
	int flag = 0;

	int lena = a.size();	
	int lenb = b.size();

	vector <int> ans;

	for (int i = 0; i < (min(lena, lenb)); i++)
		{
			flag += a[i] + b[i];
			ans.push_back(flag % 10);
			flag /= 10;
		}	

	for (int i = min(lena, lenb); i < max(lena, lenb); i++)
		{
			if (lena < lenb)
				flag += b[i];
			else
				flag += a[i];

			ans.push_back(flag % 10);
			flag /= 10;
		}

	while (flag)
		{
			ans.push_back(flag % 10);
			flag /= 10;
		}

	return ans;	
}

vector <int> operator * (const vector <int> &a, int k)
{
	long long flag = 0;

	int lena = a.size();

	vector <int> ans;

	for (int i = 0; i < lena; i++)
		{
			flag += a[i] * k;

			ans.push_back(flag % 10);
			
			flag /= 10;
		}

	while (flag)
		{
			ans.push_back(flag % 10);
			flag /= 10;
		}

	return ans;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;

	vector <vector <int> > dp(n + 1);

	dp[0].push_back(0);
	dp[1].push_back(k - 1);

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 2] * (k - 1) + dp[i - 1] * (k - 1);

	print(dp[n] + dp[n - 1]);

	return 0;
}

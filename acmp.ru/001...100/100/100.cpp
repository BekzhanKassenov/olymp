#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> operator + (const vector <int>& a, const vector <int>& b)
{
	int flag = 0;

	int lena = a.size(), lenb = b.size();

	vector <int> ans;

	for (int i = 0; i < max(lena, lenb); i++)
		{
			if (i < lena)
				flag += a[i];

			if (i < lenb)
				flag += b[i];

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

vector <int> operator * (const vector <int>& a, int k)
{
	long long flag = 0;

	vector <int> ans;

	for (size_t i = 0; i < a.size(); i++)
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

vector <int> operator * (const vector <int>& a, const vector <int>& b)
{
	int lena = a.size(), lenb = b.size();

	if (lena < lenb)
		return b * a;

	vector <int> ans(1);	

	for (int i = 0; i < lenb; i++)
		{
			vector <int> tmp = a * b[i];

			reverse(tmp.begin(), tmp.end());

			for (int j = 0; j < i; j++)
				tmp.push_back(0);

			reverse(tmp.begin(), tmp.end());

			ans = ans + tmp;	
		}

	reverse(ans.begin(), ans.end());

	while (ans[0] == 0)
		ans.erase(ans.begin());

	reverse(ans.begin(), ans.end());	

  	return ans;
}

void print(const vector <int>& a)
{
	for (int i = a.size() - 1; i >= 0; i--)
		cout << a[i];

	cout << endl;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	if (n & 1)
		{
			cout << 0;
			return 0;
		}

	n >>= 1;

	vector <vector <vector <int> > > dp(n + 2, vector <vector <int> > (n * 9 + 1, vector <int> (1)));

	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n * 9 + 1; j++)
				for (int k = 0; k <= 9; k++)
					{
						if (j + k < n * 9 + 1)
							dp[i + 1][j + k] = dp[i + 1][j + k] + dp[i][j];
					}   
		}

	vector <int> ans(1);

	for (int i = 0; i < n * 9 + 1; i++)
		ans = ans + dp[n][i] * dp[n][i];

	print(ans);

	return 0;
}

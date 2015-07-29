#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void print(const vector <int>& a)
{
	for (int i = a.size() - 1; i >= 0; i--)
		cout << a[i];

	cout << endl;	
}

vector <int> operator + (const vector <int>& a, const vector <int>& b)
{
	vector <int> ans;

	int flag = 0;

	int sa = a.size();
	int sb = b.size();

	for (int i = 0; i < min(sa, sb); i++)
		{
			flag += a[i] + b[i];

			ans.push_back(flag % 10);

			flag /= 10;
		}

	for (int i = min(sa, sb); i < max(sa, sb); i++)
		{
			if (sa < sb)
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

vector <int> per[10];

void build()
{
	per[1].push_back(8);
	per[1].push_back(6);

	per[2].push_back(7);
	per[2].push_back(9);

	per[3].push_back(4);
	per[3].push_back(8);

	per[4].push_back(0);
	per[4].push_back(3);
	per[4].push_back(9);

	per[6].push_back(1);
	per[6].push_back(7);
	per[6].push_back(0);

	per[7].push_back(2);
	per[7].push_back(6);

	per[8].push_back(1);
	per[8].push_back(3);

	per[9].push_back(2);
	per[9].push_back(4);

	per[0].push_back(4);
	per[0].push_back(6);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	build();

	vector <vector <int> > f(10), dp(10);

	for (int i = 0; i < 10; i++)
		{
			if (i == 0 || i == 8)
				f[i].push_back(0);
			else
				f[i].push_back(1);	

			dp[i].push_back(0);
		}

	for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
				{
					dp[j] = vector <int>(1);
					for (size_t k = 0; k < per[j].size(); k++)
						dp[j] = dp[j] + f[per[j][k]];
				}

			f = dp;
		}

	vector <int> ans;

	ans.push_back(0);

	for (int i = 0; i < 10; i++)
		ans = ans + f[i];

	print(ans);
}

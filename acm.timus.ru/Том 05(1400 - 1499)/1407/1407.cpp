#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> dv (const vector <int>& a)
{
	vector <int> ans;

	int flag = 0;

	for (int i = a.size() - 1; i >= 0; i--)
		{
			flag = flag * 10 + a[i];

			ans.push_back(flag / 2);

			flag %= 2;
		}

	while (ans[0] == 0)
		ans.erase(ans.begin());

	reverse(ans.begin(), ans.end());

	return ans;	
}

int md(const vector <int>& a)
{
	int ans = 0;

	for (int i = a.size() - 1; i >= 0; i--)
		{
			ans = ans * 10 + a[i];

			ans %= 2;
		}

	return ans;	
}

bool can(const vector <int>& t, int n)
{
	vector <int> a = t;

	for (int i = 0; i < n; i++)
		{
			if (md(a) == 0)
				a = dv(a);
			else
				return false;	
		}

	return true;	
}

int main()
{
	int n;

	cin >> n;

	vector <int> a;

	a.push_back(2);

	for (int i = 2; i <= n; i++)
		{
			a.push_back(1);

			if (!can(a, i))
				a[a.size() - 1] = 2;
		}

	for (int i = a.size() - 1; i >= 0; i--)
		cout << a[i];	
}

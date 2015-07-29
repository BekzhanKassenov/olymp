#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> operator + (const vector <int>& a, const vector <int>& b)
{
	vector <int> ans;

	int flag = 0;

	int sza = a.size(), szb = b.size();

	for (int i = 0; i < min(sza, szb); i++)
		{
			flag += a[i] + b[i];

			ans.push_back(flag % 10);

			flag /= 10;
		}

	for (int i = min(sza, szb); i < max(sza, szb); i++)
		{
			if (sza < szb)
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

vector <int> operator * (const vector <int>& a, int k)
{
	long long flag = 0;

	vector <int> ans;

	for (size_t i = 0; i < a.size(); i++)
		{
			flag += a[i] * 1ll * k;

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
	vector <int> ans(1);

	int lena = a.size(), lenb = b.size();

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

	while (!ans.empty() && ans[0] == 0)
		ans.erase(ans.begin());

	if (ans.empty())
		ans.push_back(0);

	reverse(ans.begin(), ans.end());

	return ans;
}

void print(const vector <int>& a)
{
	for (int i = (int)a.size() - 1; i >= 0; i--)
		cout << a[i];

	cout << endl;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	if (n == 0)
		{
			cout << 0;
			return 0;
		}

	vector <int> f, f1, f2;

	f.push_back(1);
	f1.push_back(1);
	f2.push_back(1);

	for (int i = 2; i <= n; i++)
		{
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}

	print(f * f);

	return 0;	
}

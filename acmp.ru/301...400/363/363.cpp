#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ostream& operator << (ostream& c, const vector <int>& a)
{
	for (int j = (int)a.size() - 1; j >= 0; j--)
		c << a[j];

	return c;	
}

vector <int> operator + (const vector <int>& a, const vector <int>& b)
{
	vector <int> ans;

	int lena = a.size(), lenb = b.size();

	int flag = 0;

	for (int i = 0;  i < min(lena, lenb); i++)
		{
			flag += a[i] + b[i];
			ans.push_back(flag % 10);
			flag /= 10;
		}

	for (int i = min(lena, lenb); i < max(lena, lenb); i++)
		{
			if (lena > lenb)
				flag += a[i];
			else
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

	int lena = a.size();

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

vector <int> operator * (const vector <int>& a, const vector <int>& b)
{
	int lena = a.size(), lenb = b.size();

	vector <int> ans;

	ans.push_back(0);

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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, t;

	cin >> s >> t;

	vector <int> a(s.size());

	for (size_t i = 0; i < a.size(); i++)
		a[i] = s[i] - '0';

	reverse(a.begin(), a.end());

	vector <int> b(t.size());

	for (size_t i = 0; i < b.size(); i++)
		b[i] = t[i] - '0';

	reverse(b.begin(), b.end());

	vector <int> ans = a * b;

	for (int i = ans.size() - 1; i >= 0; i--)
		printf("%d", ans[i]);

	return 0;	
}

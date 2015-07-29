#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

ostream& operator << (ostream& c, const vector <int>& a)
{
	for (int i = a.size() - 1; i >= 0; i--)
		c << a[i];

	return c;	
}

vector <int> operator + (const vector <int>& a, int k)
{
	vector <int> ans;

	for (int i = 0; i < (int)a.size(); i++)
		{
			k += a[i];
			ans.push_back(k % 10);
			k /= 10;
		}

	while (k)
		{
			ans.push_back(k % 10);
			k /= 10;
		}	

	return ans;	
}

vector <int> operator - (const vector <int>& b, int k)
{
	vector <int> a = b;

	a[0] -= k;

	int i = 0;

	int len = a.size();

	while (i < len - 1 && a[i] < 0)
		{
			a[i] += 10;
			a[i + 1]--;
		}

	while (a.back() == 0)
		a.erase(--a.end());

	return a;	
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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> f, ans;

	f.push_back(2);

	for (int i = 0; i < n; i++)
		{
			ans = (f - 2) * 3 + 4;
			f = ans;
		}

	cout << f << endl;	

	return 0;
}

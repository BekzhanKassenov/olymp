#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void print(const vector <int> &a)
{
	for (int i = (int)a.size() - 1; i >= 0; i--)
		cout << a[i];

	cout << endl;	
}

vector <int> operator + (const vector <int> &a, const vector <int> &b)
{
	int flag = 0;

	vector <int> ans;

	int lena = a.size(), lenb = b.size();

	for (int i = 0; i < min(lena, lenb); i++)
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

vector <int> operator * (const vector <int> &a, int k)
{
	long long flag = 0;

	vector <int> ans;

	for (int i = 0; i < (int)a.size(); i++)
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

	int n;

	cin >> n;

	if (n == 1)
		{
			cout << 0;
			return 0;
		}

	vector <int> f (1, 1), f1 (1, 0), k(1, 1);

	for (int i = 2; i <= n; i++)
		{
			k = (f + f1) * (i - 1);

		  	f = f1;
		  	
		  	f1 = k;
		}

	print(k);

	return 0;
}

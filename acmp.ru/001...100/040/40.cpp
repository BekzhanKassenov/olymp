#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> operator * (const vector <int> &a, int k)
{
	long long flag = 0;

	vector <int> ans;

	for (int i = 0; i < (int)a.size(); i++)
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

void output(const vector <int> &a)
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

	vector <int> a;

	a.push_back(1);

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			a = a * 2;
		}

	output(a);

	return 0;	
}

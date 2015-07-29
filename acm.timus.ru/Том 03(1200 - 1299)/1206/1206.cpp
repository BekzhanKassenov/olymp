#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> operator * (vector <int> &a, int n)
{
	long long tmp = 0;

	vector <int> ans;

	for (int i = 0; i < (int)a.size(); i++)
		{
			tmp += n * 1ll * a[i];
			ans.push_back(tmp % 10);
			tmp /= 10;
		}

	while (tmp)
		{
			ans.push_back(tmp % 10);
			tmp /= 10;
		}

	return ans;
}

void print(vector <int> &a)
{
	for (int i = (int)a.size() - 1; i >= 0; i--)
		cout << a[i];

	cout << endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> a(2);

	a[0] = 6;
	a[1] = 3;

	for (int i = 0; i < n - 1; i++)
		a = a * 55;

	print(a);

  	return 0;
}

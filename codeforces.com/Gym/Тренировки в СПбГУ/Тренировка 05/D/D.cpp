// This solution based on Fenwick tree

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <long long> t, a;

int n;

void upd(int pos, int val)
{
	for (int i = pos; i < n; i |= (i + 1))
		t[i] += val;
}

long long sum(int pos)
{
	long long ans = 0;

	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
		ans += t[i];

	return ans;
}

long long sum(int l, int r)
{
	return (sum(r) - sum(l - 1));
}

int main()
{
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);

	cin >> n;

	a.resize(n);
	t.resize(n);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];

			upd(i, a[i]);
		}

	int m;

	cin >> m;

	for (int i = 0; i < m; i++)
		{
			int l, r;

			cin >> l >> r;

			cout << sum(l - 1, r - 1) << endl;
		}

	return 0;	
}

// This solution based on Segment tree

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <long long> a, t;

void build(int v, int l, int r)
{
	if (l > r)
		return;

	if (l == r)
		{
			t[v] = a[l];
			return;
	  	}

	int tw = v << 1;

	int m = (l + r) >> 1;

	build(tw, l, m);
	build(tw + 1, m + 1, r);

	t[v] = t[tw] + t[tw + 1];
}

long long sum(int v, int cur_l, int cur_r, int l, int r)
{
	if (cur_l > cur_r)
		return 0;

	if (cur_l == cur_r)
		{
			if (cur_l >= l && cur_l <= r)
				return t[v];
			else
				return 0;
		}

	if (cur_l > r || cur_r < l)
		return 0;

	if (cur_l >= l && cur_r <= r)
		return t[v];


	int tw = v << 1;

	int m = (cur_l + cur_r) >> 1;

	return sum(tw, cur_l, m, l, r) + sum(tw + 1, m + 1, cur_r, l, r);
}

int main()
{
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);

	int n;

	cin >> n;

	a.resize(n);

	t.resize(4 * n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	build(1, 0, n - 1);

	int m;

	cin >> m;

	for (int i = 0; i < m; i++)
		{
			int l, r;

			cin >> l >> r;

			l--, r--;

			cout << sum(1, 0, n - 1, l, r) << endl;
		}

	return 0;	
}

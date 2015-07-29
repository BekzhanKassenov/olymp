#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> t;

vector <int> a;

int n;

void upd(int val, int pos)
{
	for (int i = pos; i < n; i |= (i + 1))
		t[i] += val;
}

int sum(int pos)
{
	int ans = 0;

	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
		ans += t[i];

	return ans;
}

int sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	a.resize(n);
	t.resize(n);

	for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);

			upd(a[i], i);
		}

	int m;

	scanf("%d", &m);

	int l, r;

	for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &l, &r);

			l--, r--;

			printf("%d\n", sum(l, r));
		}

	return 0;	
}
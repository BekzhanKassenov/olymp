#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define INF (int) 2e9

vector <int> a;

vector <int> t;

void build(int v, int l, int r)
{
	if (l > r)
		return;

	if (l == r)
		{
			t[v] = a[l];
			return;
		}

	int m = (l + r) >> 1;

	build(v << 1, l, m);
	build((v << 1) + 1, m + 1, r);

  	t[v] = max(t[v << 1], t[(v << 1) + 1]);
}

int get_ans(int v, int cur_l, int cur_r, int l, int r)
{
	if (cur_l > cur_r)
		return 0;

	if (cur_l == cur_r && (cur_l < l || cur_l > r))
		return 0;

	if (cur_l < cur_r && (cur_l > r || cur_r < l))
		return 0;

	if (cur_l >= l && cur_r <= r)
		return t[v];
	else
		{
			int m = (cur_l + cur_r) >> 1;

			int tmp = max(get_ans((v << 1), cur_l, m, l, r), get_ans((v << 1) + 1, m + 1, cur_r, l, r));

			return tmp;
		}
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
 	#endif

 	int m;

 	scanf("%d", &m);

 	int tmp;
 	scanf("%d", &tmp);

 	while (tmp != -1)
 		{
 			a.push_back(tmp);
 			scanf("%d", &tmp);
 		}

 	int n = a.size();

 	t.resize(4 * n + 1);

 	build(1, 0, n - 1);

 	for (int i = 0; i <= n - m; i++)
 		{
 			printf("%d\n", get_ans(1, 0, n - 1, i, i + m - 1));
 		}
 	return 0;
}


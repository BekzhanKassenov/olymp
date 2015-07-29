#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

vector <int> col;

int get_col(int v)
{
	if (col[v] == v)
		return v;
    
   return (col[v] = get_col(col[v]));	
}

bool ver_union(int a, int b)
{
	a = get_col(a);

	b = get_col(b);

	if (a == b)
		return false;

	if (rand() % 2)
		col[b] = a;
	else
		col[a] = b;

	return true;	
}

void init(int n)
{
	col.resize(n);

	srand(time(0));

	for (int i = 0; i < n; i++)
		col[i] = i;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	
	scanf("%d", &n);

	int m;

	scanf("%d", &m);

	vector <PII> a(m);

	for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a[i].F, &a[i].S);

			a[i].F --, a[i].S --;
		}

	vector <bool> used(m);

	int cnt;

	scanf("%d", &cnt);

	vector <int> er(cnt);

	vector <int> cans(cnt);

	for (int i = 0; i < cnt; i++)
		{
			scanf("%d", &er[i]);

			er[i]--;

			used[er[i]] = true;
		}

	init(n);

	int ans = n;

	for (int i = 0; i < m; i++)
		{
			if (!used[i])
				if (ver_union(a[i].F, a[i].S))
					ans--;
		}

	for (int i = cnt - 1; i >= 0; i--)
		{
			cans[i] = ans;
			if (ver_union(a[er[i]].F, a[er[i]].S))
				{
					ans--;
				}
		}

	for (int i = 0; i < cnt; i++)
		printf("%d ", cans[i]);

	return 0;
}

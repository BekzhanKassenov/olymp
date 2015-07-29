#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define INF (int)2e9

typedef struct Tree* PTree;

struct Tree
{
	int key, prior;

	int cnt, mn;

	PTree l, r;

	Tree () {}

	Tree (int key) : key(key), mn(key), prior((rand() << 16) + rand()), l(NULL), r(NULL), cnt(1) {}
};

int cnt(PTree t)
{
	return (t ? t -> cnt : 0);
}

int mn(PTree t)
{
	return (t ? t -> mn : INF);
}

void upd(PTree t)
{
	if (!t)
		return;;

	t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;

	t -> mn = min(min(mn(t -> l), mn(t -> r)), t -> key);
}

void split(PTree t, PTree &l, PTree &r, int key, int add = 0)
{
	if (!t)
		{
			r = l = NULL;
			return;
		}

	int cur = add + cnt(t -> l);

	if (cur >= key)
		{
			split(t -> l, l, t -> l, key, add);
			
			r = t;
		}
	else
		{
			split(t -> r, t -> r, r, key, cur + 1);

			l = t;
		}

	upd(t);
}

void merge(PTree &t, PTree l, PTree r)
{
	if (!l || !r)
		{
			t = l ? l : r;

			upd(t);

			return;
		}

	if (l -> prior > r -> prior)
		{
			merge(l -> r, l -> r, r);

			t = l;
		}
	else
		{
			merge(r -> l, l, r -> l);

			t = r;
		}

	upd(t);
}

void insert(PTree &t, PTree it, int pos)
{
	PTree p1, p2;

	split(t, p1, p2, pos);

	merge(t, p1, it);

	merge(t, t, p2);
}

int get_min(PTree t, int l, int r)
{
	PTree p1, p2, p3;

	split(t, p1, p2, l);

	split(p2, p2, p3, r - l + 1);

	int ans = mn(p2);

	merge(t, p1, p2);

	merge(t, t, p3);

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	char c;

	PTree t = NULL;

	int a, b;

	for (int i = 0; i < n; i++)
		{
		   cin >> c >> a >> b;

			if (c == '+')
				{
					PTree it = new Tree(b);
					insert(t, it, a); 
				}
			else
				{
					a--, b--;

					printf("%d\n", get_min(t, a, b));
				}
		}

	return 0;
}

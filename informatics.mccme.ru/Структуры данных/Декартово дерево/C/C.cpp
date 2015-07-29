#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Tree* PTree;

struct Tree
{
	int key, prior;

	int cnt;

	PTree l, r;

	Tree () {}

	Tree (int key) : key(key), prior((rand() << 10) + rand()), cnt(1), l(NULL), r(NULL) {}
};

void output(PTree t)
{
	if (!t)
		return;

	output(t -> l);

	printf("%d ", t -> key + 1);

	output(t -> r);
}

int cnt(PTree t)
{
   return (t ? t -> cnt : 0);
}

void upd(PTree t)
{
	if (!t)
		return;

	t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;
}

void split(PTree t, PTree &l, PTree &r, int key, int add = 0)
{
	if (!t)
		{
			l = r = NULL;
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

void query(PTree &t, int l, int r)
{
	PTree p1, p2, p3;

	split(t, p1, p2, l);
	split(p2, p2, p3, r - l + 1);

	merge(t, p2, p1);
	merge(t, t, p3);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	scanf("%d%d", &n, &m);

	PTree t = NULL;

	for (int i = 0; i < n; i++)
		{
			PTree it = new Tree(i);

			merge(t, t, it);
		}

	int l, r;

	for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &l, &r);

			l--, r--;

			query(t, l, r);
		}

	output(t);

	return 0;
}

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define INF (int)2e9

struct Tree
{
	int y, val, cnt, min_val;
	Tree * l, * r;

	bool rev;

	Tree () : l(NULL), r(NULL), rev (false), cnt(0) {}

	Tree (int val) : l(NULL), r(NULL), rev(false), cnt(0), y((rand() << 16) + rand()), val(val), min_val(val) {}
};

typedef Tree* PTree;

void output(PTree t)
{
	if (t -> l)
		output(t -> l);

	cout << t -> val << ' ' << t -> min_val << endl;

	if (t -> r)
		output(t -> r);
}

int cnt(PTree t)
{
	return (t) ? (t -> cnt) : (0);
}

void upd_cnt(PTree t)
{
	if (t)
		t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;
}

int get_min(PTree t)
{
	return t ? t -> min_val : INF;
}

void upd_min(PTree t)
{
	if (t)
		{
			t -> min_val = min(min(get_min(t -> l), get_min(t -> r)), t -> val);
		}
}

void push(PTree t)
{
	if (t && t -> rev)
		{
			t -> rev = false;

			if (t -> l)
				t -> l -> rev ^= true;

			if (t -> r)
				t -> r -> rev ^= true;

			swap (t -> l, t -> r);
		}
}

void split(PTree t, int key, PTree &l, PTree &r, int add = 0)
{
	if (!t)
		{
			l = r = NULL;
			return;
		}
  	push(t);

  	int cur = add + cnt(t -> l);

  	if (key <= cur)
  		{
  			split(t -> l, key, l, t -> l, add);
  			r = t;
  		}
  	else
  		{
  			split(t -> r, key, t -> r, r, cur + 1);
  			l = t;
  		}

  	upd_min(t);

  	upd_cnt(t);
}

void merge(PTree &t, PTree l, PTree r)
{
	if (l)
		push(l);

	if (r)
		push(r);

	if (!l || !r)
		{
			t = l ? l : r;
			return;
		}

	if (l -> y > r -> y)
		{
			merge(l -> r, l -> r, r);
			t = l;
		}
	else
		{
			merge(r -> l, l, r -> l);
			t = r;
		}

	upd_cnt(t);
	upd_min(t);
}

void reverse(PTree t, int l, int r)
{
	PTree p1, p2, p3;

	split(t, l, p1, p2);

	split(p2, r - l + 1, p2, p3);

	p2 -> rev ^= true;

	//cout << "PEREVOROT " << l << ' ' << r << endl;

	//output(p2);

	merge(t, p1, p2);
	merge(t, t, p3);
}

int get_ans(PTree &t, int l, int r)
{
	PTree p1, p2, p3;

	push(t);

	split(t, l, p1, p2);
	split(p2, r - l + 1, p2, p3);

	int ans = INF;

	if (p2)
		ans = p2 -> min_val;

	//cout << endl << "ZAPROS " << l << ' ' << r << endl;

	//output(p2);

	merge(t, p1, p2);
	merge(t, t, p3); 

	return ans;
}

void insert(PTree &t, int x, int pos)
{
	PTree p1, p2;

	split(t, pos, p1, p2);

	PTree it = new Tree(x);

	merge(p1, p1, it);
	merge(t, p1, p2);
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
			int x;

			scanf("%d", &x);

			PTree it = new Tree(x);

			insert(t, x, i);
		}

	for (int i = 0; i < m; i++)
		{
			int c, l, r;

			scanf("%d%d%d", &c, &l, &r);

			l--, r--;

			if (c == 1)
				{
					reverse(t, l, r);
				}
			else
				{
					printf("%d\n", get_ans(t, l, r));
				}
		}

	return 0;
}

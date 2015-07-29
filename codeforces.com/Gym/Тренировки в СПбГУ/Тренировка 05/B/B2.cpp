// This solution based on Decart tree

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Tree* PTree;

const int INF = (int)2e9;

struct Tree
{
	int key, prior;

	int mn, mx;

	int cnt;

	PTree l, r;

	Tree (int key) : key(key), prior((rand() << 16) + rand()), mn(key), mx(key), cnt(1), l(NULL), r(NULL) {}
};

void output(PTree t)
{
	if (!t)
		return;

	output(t -> l);

	cout << t -> key << endl;

	output(t -> r);
}

int cnt(PTree t)
{
	return (t ? t -> cnt : 0);
}

int mn(PTree t)
{
	return (t ? t -> mn : INF);
}

int mx(PTree t)
{
	return (t ? t -> mx : -INF);
}

void upd(PTree &t)
{
	t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;

	t -> mn = min(mn(t -> l), mn(t -> r));

	t -> mx = max(mx(t -> l), mx(t -> r));

	t -> mn = min(t -> mn, t -> key);

	t -> mx = max(t -> mx, t -> key);
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

int get_ans(PTree &t, int l, int r)
{
	if (l == r)
		return 0;

	PTree p1, p2, p3;

	split(t, p1, p2, l);

	split(p2, p2, p3, r - l + 1);

	int ans = p2 -> mx - p2 -> mn;

	merge(t, p1, p2);
	merge(t, t, p3);

	return ans;
}

void insert(PTree &t, int pos, int val)
{
	PTree it = new Tree(val);

	PTree p1, p2, p3;

	split(t, p1, p2, pos);

	split(p2, p2, p3, 1);

	p2 = it;

	merge(t, p1, p2);

	merge(t, t, p3);
}

int main()
{
	freopen("rvq.in", "r", stdin);
	freopen("rvq.out", "w", stdout);

	int n = 100001;

	srand(time(NULL));

	PTree t = NULL;

	for (int i = 0; i < n; i++)
		{
			int sq = (i + 1) % 12345;

			sq = (sq * sq) % 12345;

			int cb = (i + 1) % 23456;

			cb = (((cb * cb) % 23456) * cb) % 23456;

			PTree it = new Tree(sq + cb);

			merge(t, t, it);
		}

	int k;

	cin >> k;

	for (int i = 0; i < k; i++)
		{
			int x, y;

			cin >> x >> y;
			
			if (x > 0)
				{
					cout << get_ans(t, x - 1, y - 1) << endl;
				}
			else
				{     	
					x *= -1;
					insert(t, x - 1, y);
				}
		}	

	return 0;
}

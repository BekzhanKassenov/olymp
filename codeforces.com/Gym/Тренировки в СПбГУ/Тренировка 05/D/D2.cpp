// This solution based on Decart tree

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Tree* PTree;

struct Tree
{
	int key, prior;

	long long sum;

	int cnt;

	PTree l, r;

	Tree() {}

	Tree(int key) : key(key), prior((rand() << 16) + rand()), cnt(1), l(NULL), r(NULL), sum((long long) key) {}
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

long long sum(PTree t)
{
	return (t ? t -> sum : 0);
}

void upd(PTree t)
{
	if (!t)
		return;

	t -> sum = t -> key + sum(t -> l) + sum(t -> r);
	t -> cnt = 1 + cnt(t -> l) + cnt(t -> r);
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

long long get_ans(PTree &t, int l, int r)
{
	PTree p1, p2, p3;

	split(t, p1, p2, l);
	split(p2, p2, p3, r - l + 1);

	long long ans = p2 -> sum;

	merge(t, p1, p2);
	merge(t, t, p3);
	
	return ans;
}

int main()
{
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);

	srand(time(NULL));

	int n;

	cin >> n;

	PTree t = NULL;

	for (int i = 0; i < n; i++)
		{
			int x;

			cin >> x;

			PTree it = new Tree(x);

			merge(t, t, it);
		}
	
	int m;

	cin >> m;

	for (int i = 0; i < m; i++)
		{
			int l, r;

			cin >> l >> r;

			l--, r--;

			cout << get_ans(t, l, r) << endl;
		}

	return 0;	
}


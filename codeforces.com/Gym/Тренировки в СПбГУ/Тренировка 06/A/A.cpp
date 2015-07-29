#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct Tree* PTree;

struct Tree
{
	int key, prior;

	int next;

	PTree l, r;

	Tree() {}
	Tree(int key) : key(key), prior((rand() << 16) + rand()), next(-1), l(NULL), r(NULL) {}
};

PTree find(PTree t, int key)
{
	if (!t)
		return NULL;

	if (t -> key == key)
		return t;

	if (key < t -> key)
		return find(t -> l, key);
	else
		return find(t -> r, key);
}

void split(PTree t, PTree &l, PTree &r, int key)
{
	if (!t)
		{
			r = l = NULL;
			return;
		}	

	if (t -> key >= key)
		{
			split(t -> l, l, t -> l, key);
			r = t;
		}
	else
		{
			split(t -> r, t -> r, r, key);
			l = t;
		}
}

PTree merge(PTree l, PTree r)
{
	if (!l || !r)
		{
			return l ? l : r;
		}

	if (l -> prior > r -> prior)
		return merge(l -> r, r);
	else
		return merge(l, r -> l);	
}

void erase(PTree &t, int key)
{
	PTree tmp = find(t, key);

	PTree k = merge(tmp -> l, tmp -> r);

	*tmp = *k;
}

void insert(PTree &t, PTree it)
{
	if (!t)
		t = it;
	else
		{
			if (it -> prior > t -> prior)
				{
					split(t, it -> l, it -> r, it -> key);
					t = it;
				}
			else
				{
					if (it -> key < t -> key)
						insert(t -> l, it);
					else
						insert(t -> r, it);	
				}
		}
}

int main()
{	
	freopen("floor4.in", "r", stdin);
	freopen("floor4.out", "w", stdout);


	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		{
			int x;

			scanf("%d", &x);

			
		}

}

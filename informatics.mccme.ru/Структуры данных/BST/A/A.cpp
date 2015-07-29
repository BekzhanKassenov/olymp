#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct Tree* PTree;

struct Tree
{
	PTree l, r;

	int key;

	Tree() {}

	Tree(int key) : key(key), l(NULL), r(NULL) {}
};

int glu = 0;

void insert(PTree &t, PTree it, int gl = 1)
{
	glu = max(gl, glu);

	if (!t)
		t = it;
	else
		{
			if (t -> key == it -> key)
				return;

			if (it -> key < t -> key)
				insert(t -> l, it, gl + 1);
			else
				insert(t -> r, it, gl + 1);	
		}	
}

int main()
{
	int n;

	PTree t = NULL;

	while (cin >> n && n != 0)
	 {
		PTree tmp = new Tree(n);

		insert(t, tmp);
	 }

	cout << glu << endl;
}

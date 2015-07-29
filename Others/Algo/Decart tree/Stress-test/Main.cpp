#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Tree* pTree;

struct Tree {
 	int x, y;
 	pTree l, r;

 	Tree () : x (0), y ((rand() << 16) + rand()), l (NULL), r (NULL){}

 	Tree (int x) : x (x), y ((rand() << 16) + rand()), l (NULL), r (NULL) {}
};

void split(pTree v, pTree& l, pTree& r, int key) {
	if (v == NULL) {
		l = r = NULL;
		return;
	}

	if (key > v -> x) {
		split(v -> r, v -> r, r, key);
		l = v;
	} else {
		split(v -> l, l, v -> l, key);
		r = v;
	}
}

pTree merge(pTree l, pTree r) {
	if (l == NULL || r == NULL)
		return (l ? l : r);

	pTree ans = NULL;

	if (l -> y > r -> y) {
		l -> r = merge(l -> r, r);
		ans = l;
	} else {
		r -> l = merge(l, r -> l);
		ans = r;
	}

	return ans;
}

pTree find(pTree root, int val) {
	if (root == NULL)
		return NULL;

	if (root -> x == val)
		return root;

	if (val < root -> x)
		return find(root -> l, val);

	return find(root -> r, val);	
}

void erase(pTree& root, int val) {
	if (root == NULL)
		return;

	if (root -> x == val)
		root = merge(root -> l, root -> r);
	else {
		if (val < root -> x)
			erase(root -> l, val);
		else
			erase(root -> r, val);	
	}
}

void insert(pTree& root, pTree it) {
	if (root == NULL) {
		root = it;
		return;
	}	

	if (it -> y > root -> y) {
		split(root, it -> l, it -> r, it -> x);
		root = it;
	} else {
		if (root -> x > it -> x)
			insert(root -> l, it);
		else
			insert(root -> r, it);	
	}
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	freopen("log", "a", stderr);

	double start = clock();

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	int x;
	char c;

	pTree root = NULL, temp;

	for (int i = 0; i < n; i++) {
		cin >> c >> x;

		switch (c) {
			case '+':
				temp = new Tree(x);
				insert(root, temp);
				break;
			case '-':
				erase(root, x);
				break;
			case '?':
				if (find(root, x))
					puts("YES");
				else
					puts("NO");	
		}
	}

	fprintf(stderr, "        %.3lf", (double)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}

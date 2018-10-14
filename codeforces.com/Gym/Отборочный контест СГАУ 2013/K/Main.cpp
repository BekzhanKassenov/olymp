#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 200010;

typedef class Node* pNode;

class Node {
	int x, y;
	pNode l, r;

	Node() : x(0), y((rand() << 16) + rand()), l(NULL), r(NULL) {}

	Node(int x) : x(x), y((rand() << 16) + rand()), l(NULL), r(NULL) {}
};

class Treap {
	pNode root;

	Treap() : root(NULL) {}

	void split(pNode v, pNode &l, pNode &r, int key) {
		if (!v) {
			l = r = NULL;
			return;
		}
		if (key <= v -> x) {
			split(v -> l, l, v -> l, key);
			r = v;
		} else {
			split(v -> r, v -> r, r, key);
			l = v;
		}
	}

	void put_on(pNode& v, pNode item) {
		if (!v) {
			v = item;
			return;
		}

		if (item -> y > v -> y) {
			split(v, item -> l, item -> r, item -> key);
			v = item;
		} else {
			if (item -> key < v -> key)
				insert(v -> l, item);
			else
				insert(v -> r, item);
		}
	}

	void insert(int val) {
		pNode item = new Node(val);
		put_on(root, item);
	}


};

set <int> t[4 * maxn];

void update(int v, int l, int r, int pos, int val) {
	if (l > r || pos < l || pos > r)
		return;

	t[v].insert(val);

	if (l < r) {
		int mid = (l + r) >> 1;
		update(v << 1, l, mid, pos, val);
		update((v << 1) + 1, mid + 1, r, pos, val);
	}
}

int get(int v, int l, int r, int pos, int val) {
	if (l > r)
		return 0;

	if (l >= 0 && r <= pos) {
		return 
	}
}
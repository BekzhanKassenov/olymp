#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Node* pNode;

struct Node {
 	int x, y, cnt;
 	pNode l, r;

 	Node() {}

 	Node(int x) : x(x), y((rand() << 16) + rand()), cnt(0), l(NULL), r(NULL) {}
};

int cnt(pNode v) {
	return (v ? v -> cnt : 0);
}

void upd_cnt(pNode v) {
	if (v)
		v -> cnt = cnt(v -> l) + cnt(v -> r) + 1;
}

void split(pNode v, pNode& l, pNode& r, int key) {
	if (!v) {
		l = r = NULL;
		return;
	}

	if (v -> x <= key) {
		split(v -> r, v -> r, r, key);
		l = v;
	} else {
		split(v -> l, l, v -> l, key);
		r = v;
	}

	upd_cnt(v);
}

pNode merge(pNode l, pNode r) {
	if (!l || !r)
		return (l ? l : r);

	pNode ans;

	if (l -> y > r -> y) 
		ans = merge(l -> r, r);
	else
		ans = merge(l, r -> l);

	upd_cnt(ans);
	return ans;
}

void insert(pNode& v, pNode it) {
	if (!v) {
		v = it;
		return;
	}

	if (it -> y > v -> y) {
		split(v, it -> l, it -> r, it -> x);
		v = it;
	} else 
		insert(it -> x < v -> x ? v -> l : v -> r, it);
}

pNode find(pNode root, int key) {
	int cur = cnt(root -> l) + 1;

	int mn = min(root -> r);

	if (key + cur <= mn && key + cur >= root -> x)
		return root;

	if (key + cur > mn)
		return find(root -> l);

	return find(root -> r);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	return 0;
}

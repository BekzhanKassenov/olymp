#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

typedef struct Node* PNode;

struct Node {
 	int key, prior, cnt;

 	PNode l, r;

 	Node() {}

 	Node(int key) : key(key), prior((rand() << 16) + rand()), cnt(1), l(NULL), r(NULL) {}
};

int n, m, l, r;

int cnt(PNode t) {
	return (t ? t -> cnt : 0);
}

void upd(PNode t) {
	if (t)
		t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;
}

void output(PNode t) {
	if (t) {
	 	output(t -> l);
	 	printf("%d ", t -> key);
	 	output(t -> r);
	}
}

void split(PNode t, PNode& l, PNode& r, int key, int add = 0) {
	if (!t) {
		l = r = NULL;
		return;
	}

	int cur = add + cnt(t -> l);

	if (key <= cur) {
		split(t -> l, l, t -> l, key, add);
		r = t;
	} else {
		split(t -> r, t -> r, r, key, cur + 1);
		l = t;
	}

	upd(t);
}

PNode merge(PNode l, PNode r) {
	if (!l || !r)
		return l ? l : r;

	PNode ans;

	if (l -> prior > r -> prior) {
		l -> r = merge(l -> r, r);
		ans = l;
	} else {
		r -> l = merge(l, r -> l);
		ans = r;	
	}

	upd(ans);

	return ans;
}

void query(PNode& t, int l, int r) {
	PNode t1, t2, t3;

	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);

	t = merge(t2, t1);
	t = merge(t, t3);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	srand(time(NULL));

	PNode root = NULL;

	for (int i = 0; i < n; i++) {
	 	PNode tmp = new Node(i + 1);

	 	root = merge(root, tmp);
	}

	for (int i = 0; i < m; i++) {
	  	scanf("%d%d", &l, &r);

	  	query(root, l - 1, r - 1);
	}

	output(root);

	return 0;
}

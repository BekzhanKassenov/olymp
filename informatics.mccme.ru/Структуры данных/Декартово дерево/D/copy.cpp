#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = (int)2e9;

typedef struct Node* PNode;

struct Node {
 	int key, prior;
 	int min_val, cnt;

 	PNode l, r;

 	Node() {}

 	Node(int key) : key(key), prior((rand() << 16) + rand()), min_val(key), cnt(1), l(NULL), r(NULL) {}
};

int cnt(PNode t) {
 	return (t ? t -> cnt : 0);
}

int min(PNode t) {
 	return (t ? t -> min_val : INF);
}

void upd(PNode t) {
	if (t) {
		t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;
		t -> min_val = min(min(min(t -> l), min(t -> r)), t -> key);
	}	
}

void split(PNode t, PNode& l, PNode& r, int key, int add = 0) {
	if (!t) {
		l = r = NULL;
		return;
	}

	int cur = cnt(t -> l) + add;

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

void insert(PNode& t, int pos, int key) {
	PNode t1, t2 = new Node(key), t3;

	split(t, t3, t1, pos);

	t = merge(t3, t2);
	t = merge(t, t1);
}

int min(PNode& t, int l, int r) {
	PNode t1, t2, t3;

	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);

	int ans = min(t2);

	t = merge(t1, t2);
	t = merge(t, t3);

	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	scanf("%d", &n);

	PNode root = NULL;

	int x, y;
	char c;

	for (int i = 0; i < n; i++) {
	    scanf("\n%c %d %d", &c, &x, &y);

		if (c == '+')
			insert(root, x, y);
		else
			printf("%d\n", min(root, x - 1, y - 1));
	}

	return 0;
}

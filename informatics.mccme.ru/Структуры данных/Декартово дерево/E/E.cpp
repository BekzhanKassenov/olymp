#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Node* PNode;

const int INF = (int)2e9;

struct Node {
 	int key, prior;
 	int cnt, min_val;
 	bool rev;
 	PNode l, r;

 	Node() {}

 	Node(int key) : key(key), prior((rand() << 16) + rand()), cnt(1), min_val(key), rev(false), l(NULL), r(NULL) {}
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

void push(PNode t) {
	if (t && t -> rev) {
		if (t -> l)
			t -> l -> rev ^= 1;

		if (t -> r)
			t -> r -> rev ^= 1;

		t -> rev = false;
		swap(t -> l, t -> r);	
	}
}

void split(PNode t, PNode& l, PNode& r, int key, int c = 0) {
	push(t);

	if (!t) {
		l = r = NULL;
		return;
	}

	int cur = cnt(t -> l) + c;

	if (key <= cur) {
		split(t -> l, l, t -> l, key, c);
		r = t;
	} else {
		split(t -> r, t -> r, r, key, cur + 1);
		l = t;
	}
	                     
	upd(t);
}

void merge(PNode& t, PNode l, PNode r) {
	push(l);
	push(r);

	if (!l || !r) {
		t = l ? l : r;
		return;
	}

	if (l -> prior > r -> prior) {
		merge(l -> r, l -> r, r);
		t = l;
	} else {
		merge(r -> l, l, r -> l);
		t = r;
	}

	upd(t);
}   	

int get_ans(PNode& t, int l, int r) {
	PNode t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);

	int ans = min(t2);

	merge(t, t1, t2);
	merge(t, t, t3);

	return ans;
}

void reverse(PNode& t, int l, int r) {
	PNode t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);

	if (t2)
		t2 -> rev ^= 1;

	merge(t, t1, t2);
	merge(t, t, t3);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	srand(time(NULL));

	int x;

	PNode root = NULL;

	for (int i = 0; i < n; i++) {
		cin >> x;
		PNode tmp = new Node(x);
		merge(root, root, tmp);
	}

	for (int i = 0; i < m; i++) {
		int c, l, r;

		cin >> c >> l >> r;

		l--, r--;

		if (c == 1)
			reverse(root, l, r);
		else
			cout << get_ans(root, l, r) << endl;	
	}

	return 0;
}

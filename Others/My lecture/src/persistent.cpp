#include <cstdio>

using namespace std;

const int MAXN = 100010;

struct Node {
  	Node *left, *right;
  	int sum;

  	Node() : left(NULL), right(NULL), sum(0) { }

  	Node(Node *left, Node *right, int sum) : left(left), right(right), sum(sum) { }
};

typedef Node* pNode;

inline pNode get_node(pNode& v) {
 	if (v == NULL)
 		v = new Node();

	return v;
}

int a[MAXN], n, m;
int type, x, pos, l, r;
pNode version[2 * MAXN];
int last_version;

void build(pNode v, int l, int r) {
 	if (l == r) {
 	 	v -> sum = a[l];
 	 	return;
 	}

 	int mid = (l + r) / 2;
 	build(get_node(v -> left), l, mid);
 	build(get_node(v -> right), mid + 1, r);

 	v -> sum = get_node(v -> left) -> sum + get_node(v -> right) -> sum;
}

pNode update(pNode v, int l, int r, int pos, int val) {
 	if (l == r) {
 	 	return new Node(NULL, NULL, val);
 	}

 	int mid = (l + r) / 2;
 	pNode result = new Node(v -> left, v -> right, 0);

 	if (pos <= mid) {
 		result -> left = update(get_node(v -> left), l, mid, pos, val);;
 	} else {
 		result -> right = update(get_node(v -> right), mid + 1, r, pos, val);
 	}

 	result -> sum = get_node(result -> left) -> sum + get_node(result -> right) -> sum;
 	return result;
}

int get_sum(pNode v, int l, int r, int ql, int qr) {
 	if (l > r || ql > r || l > qr) {
 	 	return 0;
 	}

 	if (ql <= l && r <= qr) {
 	 	return v -> sum;
 	}

 	int mid = (l + r) / 2;
 	
 	return get_sum(get_node(v -> left), l, mid, ql, qr) + get_sum(get_node(v -> right), mid + 1, r, ql, qr);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	}

	build(get_node(version[0]), 0, n - 1);
	last_version = 1;

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
	 	scanf("%d", &type);

	 	if (type == 0) { // update
	 	 	scanf("%d%d", &pos, &x);
	 	 	version[last_version] = update(version[last_version - 1], 0, n - 1, pos, x);
	 	 	last_version++;
	 	 	a[pos] = x;
	 	} else {
	 		scanf("%d%d", &l, &r);
	 		printf("%d\n", get_sum(version[last_version - 1], 0, n - 1, l, r));
	 	}
	}

	return 0;
}

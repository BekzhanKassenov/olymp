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
pNode root = NULL;
pNode ver[2 * MAXN];
int last_ver;

pNode update(pNode v, int l, int r, int pos, int val) {
 	if (l == r) {
 	 	return new Node(NULL, NULL, val);
 	}

 	int mid = (l + r) / 2;

 	pNode res = new Node(v -> left, v -> right, v -> sum);

 	if (pos <= mid)
 		res -> left = update(get_node(v -> left), l, mid, pos, val);
 	else
 		res -> right = update(get_node(v -> right), mid + 1, r, pos, val);

 	res -> sum = get_node(res -> left) -> sum + get_node(res -> right) -> sum;
 	return res;
}

int get_sum(pNode v, int l, int r, int ql, int qr) {
 	if (l > r || ql > r || l > qr) {
 	 	return 0;
 	}

 	if (ql <= l && r <= qr) {
 	 	return v -> sum;
 	}

 	int mid = (l + r) / 2;
 	
 	return get_sum(get_node(v -> left), l, mid, ql, qr) + 
 		   get_sum(get_node(v -> right), mid + 1, r, ql, qr);
}

int main() {
	scanf("%d", &n);

	last_ver = 1;
	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	 	ver[last_ver] = update(get_node(ver[last_ver - 1]), 0, n - 1, i, a[i]);
	 	last_ver++;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
	 	scanf("%d", &type);

	 	if (type == 0) { // update
	 	 	scanf("%d%d", &pos, &x);
	 	 	ver[last_ver] = update(get_node(ver[last_ver - 1]), 0, n - 1, pos, x);
	 	 	last_ver++;
	 	 	a[pos] = x;
	 	} else {
	 		scanf("%d%d", &l, &r);
	 		printf("%d\n", get_sum(ver[last_ver - 1], 0, n - 1, l, r));
	 	}
	}

	return 0;
}

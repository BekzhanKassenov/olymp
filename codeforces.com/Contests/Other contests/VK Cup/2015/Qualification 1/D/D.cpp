/****************************************
**      Solution by NU: Black Kex      **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int get_prior() {
	static vector <int> vec;
	static bool initialized = false;
	static int last_pos = 0;

	if (!initialized) {
		initialized = true;
		srand(time(NULL));
		vec.resize(MAXN);

		for (size_t i = 0; i < vec.size(); i++) {
			vec[i] = i;
		}

		random_shuffle(all(vec));
	}

	return vec[last_pos++];
}

struct Node {
	int key, prior;
	int val, query_num;
	int flag;
	Node *left, *right;

	Node() : key(0), 
             prior(get_prior()), 
             val(INF), 
             query_num(0), 
             flag(INF), 
             left(NULL), 
             right(NULL) { }
};

typedef Node* pNode;

void push(pNode v) {
	if (v != NULL && v->flag != INF) {
		v->val = min(v->val, v->flag);

		if (v->left != NULL) {
			v->left->flag = min(v->left->flag, v->flag);
		} 

		if (v->right != NULL) {
			v->right->flag = min(v->right->flag, v->flag);
		}

		v->flag = INF;
	}
}

void split(pNode v, pNode& l, pNode& r, int key) {
	if (v == NULL) {
		l = r = NULL;
		return;
	}

	push(v);
	if (key < v->key) {
		split(v->left, l, v->left, key);
		r = v;
	} else {
		split(v->right, v->right, r, key);
		l = v;
	}

	push(l);
	push(r);
}

pNode merge(pNode l, pNode r) {
	push(l);
	push(r);

	if (l == NULL || r == NULL) {
		return (l == NULL) ? r : l;
	}

	pNode ans = NULL;
	if (l->prior > r->prior) {
		l->right = merge(l->right, r);
		ans = l;
	} else {
		r->left = merge(l, r->left);
		ans = r;
	}

	push(ans);

	return ans;
}

void insert(pNode& root, pNode item) {
	if (root == NULL) {
		root = item;
		return;
	}

	if (root->prior < item->prior) {
		split(root, item->left, item->right, item->key);
		root = item;
		return;
	}

    push(root);
	if (item->key < root->key) {
		insert(root->left, item);
	} else {
		insert(root->right, item);
	}
}

int n, m;
int a[MAXN], l[MAXN], r[MAXN];
int ans[MAXN];
vector <pair <int, int> > q[MAXN];
map <int, int> pos;
int next[MAXN];
pNode root = NULL;

void update_ans(pNode root) {
	if (root == NULL) {
		return;
	}

	push(root);

    if (root->val != INF) {
    	ans[root->query_num] = root->val;
	}

    update_ans(root->left);
	update_ans(root->right);
}

void output(pNode v) {
    if (v != NULL) {
        output(v->left);
        cout << v->key << ' ';
        output(v->right);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
    	scanf("%d%d", &l[i], &r[i]);
    	if (l[i] != r[i]) {
            q[l[i]].push_back(make_pair(r[i], i));
        }
    }

    for (int i = 1; i <= n; i++) {
    	next[pos[a[i]]] = i;
    	pos[a[i]] = i;
    }
    
    memset(ans, 255, sizeof ans);

    for (int i = 1; i <= n; i++) {
    	for (size_t j = 0; j < q[i].size(); j++) {
    		pNode temp = new Node();
    		temp->key = q[i][j].first;
    		temp->query_num = q[i][j].second;
    		insert(root, temp);
    	}

    	if (next[i] != 0) {
    		pNode tree1, tree2;
    		split(root, tree1, tree2, next[i] - 1);

    		if (tree2 != NULL) {
    			tree2->flag = min(tree2->flag, next[i] - i);
    		}

    		root = merge(tree1, tree2);
    	}

    	pNode tree_old, tree_new;
    	split(root, tree_old, tree_new, i);

    	update_ans(tree_old);
    	root = tree_new;

        /*cout << i << ": ";
        output(tree_old);
        cout << endl;
        output(tree_new);
        cout << endl;*/
    }

    update_ans(root);

    for (int i = 1; i <= m; i++) {
    	printf("%d\n", ans[i]);
    }

    return 0;
}

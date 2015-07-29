#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define MP make_pair
#define F first
#define S second

struct Node {
	pair <int, int> key; 
	int prior;

	int l, r;

	Node() : key(MP(-1, -1)), prior((rand() << 16) + rand()), l(0), r(0) {}
} t[500000];

int last = 1;

void split(int cur, int& l, int& r, int key) {
	if (!cur) {
		l = r = 0;
		return;
	}

	if (key < t[cur].key.F) {
		split(t[cur].l, l, t[cur].l, key);
		r = cur;
	} else {
		split(t[cur].r, t[cur].r, r, key);
		l = cur;
	}
}

int merge(int l, int r) {
	if (!l || !r)
		return (l ? l : r);

	if (t[l].prior > t[r].prior) {
		t[l].r = merge(t[l].r, r);
		return l;
	}

	t[r].l = merge(l, t[r].l);
	return r;
}

void erase(int& root, int key) {
	if (t[root].key.F == key)
		root = merge(t[root].l, t[root].r);
	else {
		if (key < t[root].key.F)
			erase(t[root].l, key);
		else
			erase(t[root].r, key);	
	}
}

void insert(int& root, int item) {
	if (!root) {
		root = item;
		return;
	}

	if (t[item].prior > t[root].prior) {
		split(root, t[item].l, t[item].r, t[item].key.F);
		root = item;
		return;
	}

	if (t[item].key < t[root].key)
		insert(t[root].l, item);
	else
    	insert(t[root].r, item);	
}

void insert(int& root, PII key) {
	t[last].key = key;
	insert(root, last);
	last++;
}

int upper_bound(int root, int key) {
	if (!root)
		return 0;

	if (t[root].key.F > key) {
	 	int temp = upper_bound(t[root].l, key);
		
		return (temp ? temp : root);
	} else 
		return upper_bound(t[root].r, key);
}

int min(int root) {
 	if (!root || !t[root].l)
 		return root;

 	return min(t[root].l);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, k;

	scanf("%d%d", &n, &k);

	vector <vector <int> > ans;

	int root = 0;

	int x;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);

		insert(root, MP(x, i + 1));
	}	

	while (root) {
		vector <int> tmp_ans;

		int cur = min(root);

		while (cur) {
			tmp_ans.push_back(t[cur].key.S);

			int val = t[cur].key.F + k;

			erase(root, t[cur].key.F);

			cur = upper_bound(root, val);
		}

		ans.push_back(tmp_ans);
	}

	printf("%u\n", ans.size());

	for (size_t i = 0; i < ans.size(); i++) {
	    printf("%u", ans[i].size());

	 	for (size_t j = 0; j < ans[i].size(); j++)
			printf(" %d", ans[i][j]);

		puts("");
	}

	return 0;
}   	

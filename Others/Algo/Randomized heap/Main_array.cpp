#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
 	int key;

 	int l, r;

 	Node() : key(0), l(0), r(0) {}
}t [2500000];

int last = 1;

int merge(int l, int r) {
	if (!l || !r)
		return l ? l : r;

	if (t[r].key < t[l].key)
		swap(l, r);

	if (rand() & 1) 
		swap(t[l].l, t[l].r);

	t[l].r = merge(t[l].r, r);

	return l;
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	freopen("log", "a", stderr);

	double start = clock();

	ios_base :: sync_with_stdio(false);

	srand(29);

	int n;

	cin >> n;

	int x;

	char c;

	int root = 0;

	for (int i = 0; i < n; i++) {
		cin >> c;

		switch (c) {
			case '+':
				cin >> x;
				t[last++].key = x;
				root = merge(root, last - 1);
				break;
			case '-':
				if (root) {
					cout << t[root].key << endl;
					root = merge(t[root].l, t[root].r);
				} else 
					cout << -1 << endl;

				break;
			case '?':
				if (root)
					cout << t[root].key << endl;
				else
					cout << -1 << endl;	

				break;
		}
	}

	fprintf(stderr, "%.3lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	return 0;
}

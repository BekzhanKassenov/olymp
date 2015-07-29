#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = (int)2e9;

struct Node {
    int key, prior;

    int min_val, cnt;

    int l, r;

    Node() {}

    Node(int key) : key(key), prior((rand() << 16) + rand()), min_val(key), cnt(1), l(0), r(0) {}
} t[250000];

int last = 1;

int cnt(int root) {
	return (root ? t[root].cnt : 0);
}

int min_val(int root) {
	return (root ? t[root].min_val : INF);
}

void upd(int root) {
	if (root) {
		t[root].cnt = cnt(t[root].l) + cnt(t[root].r) + 1;
		t[root].min_val = min(min(min_val(t[root].l), min_val(t[root].r)), t[root].key);
	}
}

void split(int root, int& l, int& r, int key, int add = 0) {
	if (!root) {
		l = r = 0;
		return;
	}

	int cur = add + cnt(t[root].l);

	if (key <= cur) {
		split(t[root].l, l, t[root].l, key, add);
		r = root;
	} else {
	 	split(t[root].r, t[root].r, r, key, cur + 1);
	 	l = root;
	}

	upd(root);
}

int merge(int l, int r) {
	if (!l || !r) 
		return l ? l : r;

	int ans;	

	if (t[l].prior > t[r].prior) {
		t[l].r = merge(t[l].r, r);
		ans = l;
	} else {
		t[r].l = merge(l, t[r].l);
		ans = r;
	}	

	upd(ans);
	
	return ans;
}

void insert(int& root, int pos, int key) {
	int tmp = last++;

	t[tmp] = Node(key);

	int t1, t2;

	split(root, t1, t2, pos);

	root = merge(t1, tmp);
	root = merge(root, t2);
}

int min(int root, int l, int r) {
	int t1, t2, t3;

	split(root, t1, t2, l);
	split(t2, t2, t3, r - l + 1);

	int ans = min_val(t2);

	root = merge(t1, t2);
	root = merge(root, t3);

	return ans;
}

int nextInt() {
	char c;

	do {
		c = getchar();
	} while (c < '0' || c > '9');

	int res = 0;

	do {
		res = res * 10 + c - '0';
		c = getchar();
	} while (c >= '0' && c <= '9');

	return res;
}

void print(int n) {
	if (n == 0)
		return;

	print(n / 10);
	putchar(n % 10 + '0');
}

void printInt(int n) {
	if (n == 0) {
		puts("0");
		return;
	}

	if (n < 0) {
		n *= -1;
		putchar('-');
	}

	print(n);

	puts("");
}

char nextChar() {
	char c;

	do {
		c = getchar();
	} while (c != '+' && c != '?');

	return c;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	n = nextInt();

	int x, y, root = 0;

	char c;

	for (int i = 0; i < n; i++) {

		c = nextChar();
		x = nextInt();
		y = nextInt();
		if (c == '+') 
			insert(root, x, y);
		else
			printf("%d\n", min(root, x - 1, y - 1));	
	}

	return 0;
}

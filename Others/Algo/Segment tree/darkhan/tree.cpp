#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>

typedef long long i64;

using namespace std;

struct Node {
	
	Node() {
		sum = value = type = 0;
	}

	i64 sum, value;
	int type;
};

struct Tree {

	int level;
	Node Z[10 + (1 << 19)];
	
	Tree() {
		level = 1 << (18);
	}

	void updateType(int t, int v) {
		if (v == 2) {
			if (Z[t].type == 0) Z[t].type = 2;
		} else if (v == 1) {
			Z[t].type = 1;
		}
	}

	void update(int t, int l, int r) {
		if (l == r) {
			Z[t].sum = Z[t].value;
			return;
		}
		if (Z[t].type == 2) Z[t].sum = Z[2 * t].sum + Z[2 * t + 1].sum + (r - l + 1) * Z[t].value;
		if (Z[t].type == 1) Z[t].sum = (r - l + 1) * Z[t].value;
		if (Z[t].type == 0) Z[t].sum = Z[2 * t].sum + Z[2 * t + 1].sum;
	}

	void push(int t, int l, int r) {
		if (l == r || Z[t].type == 0) return;
		updateType(2 * t, Z[t].type);
		updateType(2 * t + 1, Z[t].type);
		
		if (Z[t].type == 2) {
			Z[2 * t].value += Z[t].value;
			Z[2 * t + 1].value += Z[t].value;
		} else if (Z[t].type == 1) {
			Z[2 * t].value = Z[t].value;
			Z[2 * t + 1].value = Z[t].value;
		}

		Z[t].type = Z[t].value = 0;
		update(2 * t, l, (l + r) >> 1);
		update(2 * t + 1, 1 + ((l + r) >> 1), r);
	}

	void add(int l, int r, int a, int b, int t, int x) {
		if (l > b || r < a) return;
		push(t, l, r);
		if (a <= l && r <= b) {
			updateType(t, 2);
			Z[t].value += x;
		} else {
			int mid = (l + r) >> 1;
			add(l, mid, a, b, t << 1, x);
			add(mid + 1, r, a, b, 1 + (t << 1), x);
		}
		push(t, l, r);
		update(t, l, r);
	}
	
	void add(int l, int r, int x) {
		add(level, 2 * level - 1, l + level - 1, r + level - 1, 1, x); 
	}

	void set(int l, int r, int a, int b, int t, int x) {
		if (l > b || r < a) return;
		push(t, l, r);

		if (a <= l && r <= b) {
			updateType(t, 1);
			Z[t].value = x;
		} else {
			int mid = (l + r) >> 1;
			set(l, mid, a, b, t << 1, x);
			set(mid + 1, r, a, b, 1 + (t << 1), x);
		}
		push(t, l, r);
		update(t, l, r);
	}
	
	void set(int l, int r, int x) {
		set(level, 2 * level - 1, l + level - 1, r + level - 1, 1, x); 
	}

	i64 get(int l, int r, int a, int b, int t) {
		if (l > b || r < a) return 0;
		push(t, l, r);
		if (a <= l && r <= b) {
			return Z[t].sum;
		}
		int mid = (l + r) >> 1;
		i64 res = 0;
		res += get(l, mid, a, b, t << 1);
		res += get(mid + 1, r, a, b, 1 + (t << 1));
		update(t, l, r);
		return res;
	}

	i64 get(int l, int r) {
		return get(level, 2 * level - 1, l + level - 1, r + level - 1, 1);
	}

	void print() {
		for (int i = 1; i < 2 * level; i++) {
			cout << Z[i].sum << " " << Z[i].value << " " << Z[i].type << endl;
		}
		cout << endl;
	}

};

Tree tree;

int main() {
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	while (n--) {
		char s[10];
		scanf("%s", s);
		int l, r, x;
		if (strcmp(s, "ADD") == 0) {
			scanf("%d%d%d", &l, &r, &x);
			tree.add(l, r, x);
		} else if (strcmp(s, "SET") == 0) {
			scanf("%d%d%d", &l, &r, &x);
			tree.set(l, r, x);
		} else if (strcmp(s, "GET") == 0) {
			scanf("%d%d", &l, &r);
			printf("%I64d\n", tree.get(l, r));
		} else {
			assert(0);
		}
//		tree.print();
	}

	return 0;
}

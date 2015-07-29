#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>

typedef long long i64;

using namespace std;

struct Tree {

	i64 Z[200100];

	Tree() {
		memset(Z, 0, sizeof(Z));
	}

	void add(int l, int r, int x) {
		for (int j = l; j <= r; j++) Z[j] += x;
	}


	void set(int l, int r, int x) {
		for (int j = l; j <= r; j++) Z[j] = x;
	}

	i64 get(int l, int r) {
		i64 sum = 0;
		for (int j = l; j <= r; j++) {
			sum += Z[j];
		}
		return sum;
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

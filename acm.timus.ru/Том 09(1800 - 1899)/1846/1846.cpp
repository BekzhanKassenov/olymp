#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct Node* PNode;

struct Node {
 	int key, prior, g;

 	PNode l, r;

 	Node() : key(0), prior(0), g(1), l(NULL), r(NULL) {}

 	Node(int key) : key(key), prior((rand() << 16) + rand()), g(key), l(NULL), r(NULL) {}
};

int gcd(int a, int b) {
	if (!a || !b)
		return a + b;

	return gcd(b, a % b);
}

int node_gcd(PNode t) {
	return (t ? t -> g : 0);
}

void upd_gcd(PNode t) {
	if (t) {
		t -> g = gcd(node_gcd(t -> l), node_gcd(t -> r));
		t -> g = gcd(t -> g, t -> key);
	}
}

void output(PNode t) {
	if (!t)
		return;

	output(t -> l);
	cout << t -> key << ' ' << t -> g << ' ' << t -> prior << endl;
	output(t -> r);
}

void split(PNode t, PNode& l, PNode& r, int key) {
	if (!t) {
		l = r = NULL;
		return;
	}

	if (t -> key <= key) {
		split(t -> r, t -> r, r, key);
		l = t;
	} else {
		split(t -> l, l, t -> l, key);
		r = t;
	}

 	upd_gcd(l);
   	upd_gcd(r);
	
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

   	upd_gcd(ans);

   	return ans;
}

void erase(PNode &t, int key) {
	if (!t)
		return;

	if (t -> key == key) {
		PNode tmp = merge(t -> l, t -> r);
		delete t;
		t = tmp;
		upd_gcd(t);
		return;
	}

	if (key < t -> key)
		erase(t -> l, key);
	else
		erase(t -> r, key);	

   	upd_gcd(t);
}

void insert(PNode& t, PNode it) {
	if (!t) {
		t = it;
		return;
	}

	if (it -> prior > t -> prior) {
		split(t, it -> l, it -> r, it -> key);
		t = it;
		upd_gcd(t);
		return;
	}

	if (it -> key < t -> key)
		insert(t -> l, it);
	else
		insert(t -> r, it);

	upd_gcd(t);
}

PNode root = NULL;
int n, key;
char c;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	scanf("%d", &n);

   	srand(time(NULL));

   	for (int i = 0; i < n; i++) {
   		scanf(" \n%c%d", &c, &key);
   		switch (c) {
   			case '-':
   				erase(root, key);
   				break;
   			case '+':
   				PNode tmp = new Node(key);
   				insert(root, tmp);
   				break;
   		}

   		//output(root);

   		int ans = node_gcd(root);

   		printf("%d\n", ans ? ans : 1);
   	}

   	return 0;
}

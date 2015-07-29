#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef struct Node* pNode;

struct Node {
  	char c;

  	pNode lc, rc, sib;

  	Node() {}

  	Node(char c) : c(c), lc(NULL), rc(NULL), sib(NULL) {}
};  

size_t len;

void add_letter(pNode j, char c) {
	if (!(j -> lc)) {
		j -> lc = new Node(c);
		j -> rc = j -> lc;
	} else {
		j -> rc -> sib = new Node(c);
		j -> rc = j -> rc -> sib;
	}
}

void add_string(pNode root, const string& s, size_t i) {
	bool have_next = false;

	pNode cur = root;

	for (; i < len; i++) {
		for (pNode j = cur -> lc; j != NULL && !have_next; j = j -> sib) {
			if (j -> c == s[i]) {
				cur = j;
				have_next = true;
			}
		}

		if (!have_next) {
			add_letter(cur, s[i]);
			cur = cur -> rc;
		}

		have_next = false;
	}
}

int count(pNode v) {
	int res = 0;

	for (pNode j = v -> lc; j != NULL; j = j -> sib)
		res += count(j);
	
	return res + 1;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	len = s.size();

	pNode root = new Node(0);

	for (size_t i = 0; i < len; i++) 
		add_string(root, s, i);

	cout << count(root) - 1;

	return 0;
}

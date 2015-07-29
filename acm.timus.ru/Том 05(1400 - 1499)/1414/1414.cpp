#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef struct Node* pNode;

struct Node {
 	pNode sibling, first_child, last_child;
 	bool leaf;
 	char this_char;

 	Node(char this_char) : leaf(false), this_char(this_char) {
 		sibling = first_child = last_child = NULL;
 	}
};

pNode root;

pNode add_letter(pNode v, char c) {
	pNode res = new Node(c);

	if (v -> first_child == NULL) {
		v -> first_child = res;
		v -> last_child = res;
		return res;
	}

	if (v -> first_child -> this_char > c) {
		res -> sibling = v -> first_child;
		v -> first_child = res;
		return res;
	}

	if (v -> last_child -> this_char < c) {
		v -> last_child -> sibling = res;
		v -> last_child = res;

		return res;
	}

	for (pNode i = v -> first_child; i != v -> last_child; i = i -> sibling) {
		if (i -> this_char < c && i -> sibling -> this_char > c) {
			res -> sibling = i -> sibling;
			i -> sibling = res;
		}
	}

	return res;
}

void add_string(const string& s) {
	pNode cur = root;

	for (size_t i = 0; i < s.size(); i++) {
		pNode next = NULL;

		for (pNode j = cur -> first_child; j != NULL; j = j -> sibling) {
			if (j -> this_char == s[i]) {
				next = j;
				break;
			}
		}

		if (next == NULL) 
			next = add_letter(cur, s[i]);

		cur = next;
	}

	cur -> leaf = true;
}

char res[20];

void dfs(pNode v, const string& prefix, int& cnt, int gl = 0) {
	if (v -> leaf) {
		res[gl] = '\0';
		cout << "  " << prefix << res << endl;
		cnt++; 
	}

	for (pNode i = v -> first_child; i != NULL; i = i -> sibling) {
		if (cnt >= 20)
			return;
		res[gl] = i -> this_char;
		dfs(i, prefix, cnt, gl + 1);
	}
}

void search(const string& prefix) {
	cout << prefix << endl;

	pNode cur = root;

	for (size_t i = 0; i < prefix.size(); i++) {
	 	pNode next = NULL;

	 	for (pNode j = cur -> first_child; j != NULL; j = j -> sibling) {
	 		if (j -> this_char == prefix[i]) {
	 			next = j;
	 			break;
	 		}
		}	

		if (next == NULL)
			return;

		cur = next;
	}

	int cnt = 0;

	dfs(cur, prefix, cnt);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	root = new Node(0);

	add_string("sun");

	while (getline(cin, s)) {
		char c = s[0];
		s.erase(s.begin());

		if (c == '+')
			add_string(s);
		else
			search(s);	
	}

	return 0;
}

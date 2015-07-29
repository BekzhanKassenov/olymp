#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef struct Node* pNode;

struct Node {
	bool leaf;
	int cnt;
	char ch;

 	pNode lc, rc, sib;

 	Node() : leaf(false), cnt(0), ch(0), lc(NULL), rc(NULL), sib(NULL) { }

 	void add_letter(char c) {
 		pNode tmp = new Node();

 		tmp -> ch = c;
 		
 		if (!lc) {
 			lc = rc = tmp;
 		} else {
 			rc -> sib = tmp;
 			rc = tmp;
 		}
 	}

 	pNode get_letter(char c) {
 		for (pNode it = lc; it != NULL; it = it -> sib) {
 			if (it -> ch == c)
 				return it;
 		}

 		add_letter(c);
 		return rc;
 	}
};

pNode root;

struct set_item {
 	int cnt;
 	string str;

 	set_item() { }

 	set_item(int cnt, string str) : cnt(cnt), str(str) { }

 	bool operator < (const set_item& i1) const {
 		return cnt < i1.cnt;
 	}
};

void add(char s[], int cn) {
	pNode cur = root;

	for (char* cur_c = s; *cur_c != '\0'; cur_c++) {
		cur = cur -> get_letter(*cur_c);
	}

	cur -> cnt = cn;
	cur -> leaf = true;
}

void merge(set <set_item>& s1, const set <set_item>& s2) {
	s1.insert(all(s2));

	while (s1.size() > 15)
		s1.erase(--s1.end());
}

set <set_item> dfs(pNode v, string& cur_str) {
	set <set_item> res;

	cur_str += v -> ch;

	if (v -> leaf) {
		res.insert(set_item(v -> cnt, cur_str));
	}

	for (pNode curc = v -> lc; curc != NULL; curc = curc -> sib) {
		set <set_item> tmp = dfs(curc, cur_str);
		merge(res, tmp);
	}

	cur_str.erase(--cur_str.end());

	return res;
}

set <set_item> get_ans(char s[]) {
	for (pNode cur = root; cur != NULL; ) {
		
	}
}

int n, m;
char s[100];
int cnt;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s%d", s, &cnt);

		add(s, cnt);
	}

	stringstream ss;

	scanf("%d", &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", s);

		set <set_item> st = get_ans(s);

		for (set <set_item> :: iterator it = st.begin(); it != st.end(); it++) {
			ss << it -> str << endl;
		}

		ss << endl;
	}

	cout << ss.str();

	return 0;
}

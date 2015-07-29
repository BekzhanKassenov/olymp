#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct Node* pNode;

struct Node {
 	char name[10];
 	pNode left_child, right_child, sibling;

 	Node() : left_child(NULL), right_child(NULL), sibling(NULL) {
 		memset(name, 0, sizeof name);
 	}

 	pNode add_child(char child_name[10]) {
 		pNode new_child = new Node();
 		strncpy(new_child -> name, child_name, 10);

 		if (left_child == NULL) {
 			left_child = right_child = new_child;
 		} else if (strcmp(child_name, left_child -> name) < 0){
 		 	new_child -> sibling = left_child;
 		 	left_child = new_child;
 		} else if (strcmp(child_name, right_child -> name) > 0) {
 			right_child -> sibling = new_child;
 			right_child = new_child;
 		} else {
 			for (pNode current_child = left_child; current_child != NULL; current_child = current_child -> sibling) {
 				if (strcmp(child_name, current_child -> sibling -> name) < 0) {
 					new_child -> sibling = current_child -> sibling;
 					current_child -> sibling = new_child;
 					break;
 				}
 			}
 		}

 		return new_child;
 	}

 	pNode get_ptr_to(char child_name[10]) {
 		for (pNode current_child = left_child; current_child != NULL; current_child = current_child -> sibling) {
 			if (strcmp(current_child -> name, child_name) == 0)
 				return current_child;
 		}

 		return add_child(child_name);
 	}
};

pNode root;

void dfs(pNode v, int gl = -1) {
	if (v != root) {
		for (int i = 0; i < gl; i++)
			putchar(' ');

		printf("%s\n", v -> name);
	}

	for (pNode current_child = v -> left_child; current_child != NULL; current_child = current_child -> sibling)
		dfs(current_child, gl + 1);	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	scanf("%d", &n);

	char s[100], name[10];

	root = new Node();

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		pNode current_node = root;

		char *name_ptr = name;

		for (char *s_ptr = s; *s_ptr != '\0'; s_ptr++) {
			if (*s_ptr == '\\') {
				*name_ptr = '\0';
				current_node = current_node -> get_ptr_to(name);
				name_ptr = name;
			} else {
				*name_ptr = *s_ptr;
				name_ptr++;
			}
		}

		*name_ptr = '\0';
		current_node = current_node -> get_ptr_to(name);
	}

	dfs(root);

	return 0;
}

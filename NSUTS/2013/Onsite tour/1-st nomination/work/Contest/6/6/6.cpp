#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <bitset>
#include <stack>

using namespace std;

struct group {
	int num[4];
	int total;
};

int gettype(char c) {
	if (c == '(' || c == ')')
		return 0;
	if (c == '{' || c == '}')
		return 1;
	if (c == '[' || c == ']')
		return 2;
	if (c == '<' || c == '>')
		return 3;
}

bool openb(char c) {
	return c == '(' || c == '{' || c == '[' || c == '<';
}

int t;
string s;
int n;
stack <group> st;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &t);
	
	while (t--) {
		getline(cin, s);
		n = (int) s.length();
		while (!st.empty())
			st.pop();
		
		bool ok = true;
		for (int i = 0; i < n; i++) {
			group temp;
			memset(temp.num, 0, sizeof(temp.num));
			temp.total = 0;

			if (openb(s[i])) {
				while (i < n && openb(s[i])) {
					temp.num[gettype(s[i])]++;
					temp.total++;
					i++;
				}
				st.push(temp);
			}
			else {
				while (i < n && !openb(s[i])) {
					temp.num[gettype(s[i])]++;
					temp.total++;
					i++;
				}
				while (temp.total > 0) {
					if (st.empty()) {
						ok = false;
						break;
					}
					for (int j = 0; j < 4; j++) {
						int delta = min(st.top().num[j], temp.num[j]);
						temp.total -= delta;
						st.top().total -= delta;
						temp.num[j] -= delta;
						st.top().num[j] -= delta;
					}
					bool go = false;
					if (st.top().total == 0) {
						st.pop(); 
						go = true;
					}
					if (temp.total == 0)
						break;
					else if (!go) {
						ok = false;
						break;
					}
				}
			}
			i--;
		}		

		while (!st.empty() && st.top().total == 0)
			st.pop();
		if (!st.empty())
			ok = false;

		if (ok)
			puts("T");
		else
			puts("NIL");
	}


	return 0;
}


#include <iostream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

set <string> st;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;
	
	for (int i = 0; i + k <= n; i++) {
		if (!st.insert(s.substr(i, k)).second) {
			puts("YES");
			return 0;
		}
	}

	puts("NO");
	return 0;
}
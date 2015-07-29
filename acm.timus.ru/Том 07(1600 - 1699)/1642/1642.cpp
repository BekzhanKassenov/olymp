#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

set <int> s;

int ex, n, tmp;

int find_exit(int pos, bool way) {
	int cnt = 0;
	int ans = 0;

	while (true) {
		pos += (way ? 1 : -1);

		if (s.find(pos) != s.end()) {
			way ^= 1;
			cnt++;
			if (cnt == 2)
				return -1;
		} 

		ans++;

		if (pos == ex)
			return ans;
	}

	return -1;
}

int main() {
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
 	#endif

 	scanf("%d%d", &n, &ex);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		s.insert(tmp);
	}	

	int a = find_exit(0, 1);

	if (a == -1) {
		puts("Impossible");
		return 0;
	}

	int b = find_exit(0, 0);
	
	printf("%d %d", a, b);

	return 0;
}

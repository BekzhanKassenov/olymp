#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[100];

int main() {
 	freopen("out", "r", stdin);

 	string s;
 	cin >> s;

 	int i = 0;

 	while (cin >> a[i]) {
 	 	i++;
 	}

 	int n = i;

 	i = 0;
 	for (int i = 1; i < n; i++) {
 	 	a[i] = (1ll * a[i] * a[i - 1]) % n;
 	}

 	sort(a, a + n);

 	for (int i = 0; i < n; i++) {
 	 	if (a[i] != i) {
 	 	 	puts("NO");
 	 	 	return 0;
 	 	}
 	}

 	puts("YES");

 	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, l, L;
int r, R;
int a[20010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &l, &L);
	scanf("%d%d", &r, &R);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	}



	return 0;
}

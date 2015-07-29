#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;

int *a, *b, *c;

bool check(int* a, int* b) {
	int l = 0;

 	while (l < m) {
 		if (a[l] == 1) {
 			int r = l + 1;

 			int k = b[l];

 			while ((a[r] == 1) && (r < m)) 
 				if (b[r++] != k)
 					return false;

 			l = r;
 		} else
 			l++;
 	}

 	return true;
}

int read_int() {
	char c;
	do {
		c = getchar();
	} while ((c < '0') || (c > '9'));

	int res = 0;

	do {
		res = res * 10 + c - '0';
		c = getchar();
	} while ((c >= '0') && (c <= '9'));
	
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	n = read_int(), m = read_int();

	a = new int[m];
	b = new int[m];

	for (int i = 0; i < m; i++)
		b[i] = read_int();
 	
 	for (int i = 1; i < n; i++) {
 		swap(a, b);

 		for (int j = 0; j < m; j++) 
 			b[j] = read_int();

 		if (!check(a, b) || !check(b, a)) {
 			puts("No");
 			return 0;
 		}
 	}

 	puts("Yes");
 	return 0;
}

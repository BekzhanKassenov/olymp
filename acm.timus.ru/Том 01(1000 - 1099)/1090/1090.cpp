#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10010;

int t[maxn], n, k, res = 1, ans, x, tot_ans;
char c;

inline void upd(int pos) {
	for (int i = pos; i < n; i |= (i + 1))
		t[i]++;
}

inline int get(int pos) {
	int res = 0;

	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
		res += t[i];

	return res;	
}

int read_int() {
 	int res = 0;

 	do {
 		c = fgetc(stdin);
 	} while (c < '0' || c > '9');

 	do {
 	    res = res * 10 + c - '0';
 	    c = getc(stdin);
 	} while (c >= '0' && c <= '9');

 	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	
	n = read_int();
	k = read_int();

	for (int j = 1; j <= k; j++) {
	    int* cur_ptr = t;

		for (int i = 0; i < n; i++, cur_ptr++)
			*cur_ptr = 0;

		ans = 0;

		for (int i = 0; i < n; i++) {
			x = read_int();
			ans += get(n - 1) - get(x - 1);
			upd(x - 1);
		}

		if (ans > tot_ans) {
			tot_ans = ans;
			res = j;
		}
	}

	printf("%d", res);

	return 0;
}

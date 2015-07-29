#include <stdio.h>

long long n, p, ans;

const long long cnt = (long long) (1e14);

inline long long readLL() {
 	char c;

 	do {
		c = getchar();
 	} while ((c < '0') || (c > '9'));

 	long long res = 0;

 	do {
 		res = res * 10 + c - '0';
 		c = getchar();
 	} while ((c >= '0') && (c <= '9'));

 	return res;
}

inline void putLL(long long n) {
 	if (!n)
 		return;
 	else {
 		putLL(n / 10);
 		putchar(n % 10 + '0');
 	}
}

inline void putL(long long n) {
	if (!n)
		putchar('0');
	else
		putLL(n);	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	n = readLL(), p = readLL();

   	while (n && p) {
   	 	ans = 1;

   	 	for (int i = 2; i <= n; i++) {
   	 		ans *= i;

   	 		if (ans >= cnt)
   	 			ans %= p;
   	   	}

   	   	ans %= p;

   	   	putL(ans);
   	   	putchar('\n');

   	 	n = readLL(), p = readLL();
   	}

   	return 0;
}

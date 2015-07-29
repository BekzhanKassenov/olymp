#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>

using namespace std;

#define F first
#define S second
#define MP make_pair

vector <pair <int, bool> > zapr;
int n, j, b[100000], c[100000], block[100000];
char ss[1000100], rd;
int sz = 0;

void print_int(int n) {
	if (!n)
		return;

	print_int(n / 10);
	ss[sz++] = n % 10 + '0';
}

int gcd(int a, int b) {
	if (!a || !b)
		return a + b;

   	return gcd(b % a, a);
}

int read_int() {
	char c;

	do {
	 	c = getchar();
	} while (c < '0' || c > '9');

	int res = 0;

	do {
	 	res = res * 10 + c - '0';
	 	c = getchar();
	} while (c >= '0' && c <= '9');

	return res;
}

char read_char() {
	char c;

	do {
	 	c = getchar();
	} while (c != '+' && c != '-');

	return c;
}

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	n = read_int();

	zapr.resize(n);

	for (int i = 0; i < n; i++) {
	    zapr[i].S = (read_char() - '-');
	    zapr[i].F = read_int();
	}

	map <int, bool> Map(zapr.begin(), zapr.end());

	vector <int> a;
	a.reserve(Map.size());

	for (map <int, bool> :: iterator it = Map.begin(); it != Map.end(); it++)
		a.push_back(it -> F);

	int len = a.size();
	int l = sqrt(len + .0) + 1;

	int cnt = 0, cnt1 = 0;

	for (int i = 0; i < len; i++) {
		if (cnt1 == l) {
		 	cnt++;
		 	cnt1 = 0;
		}
		block[i] = cnt;
		cnt1++;
	}	
		

   	for (int i = 0; i < n; i++) {
   		int pos = lower_bound(a.begin(), a.end(), zapr[i].F) - a.begin();

   		c[pos] += (zapr[i].S ? 1 : -1);

   		j = block[pos];

   		b[j] = 0;

   		for (int k = j * l; k < fastMin((j + 1) * l, len) && (b[j] ^ 1); k++) 
   			if (c[k])
   				b[j] = gcd(b[j], a[k]);

   		int ans = 0;

   		for (j = 0; j < l + 1 && (ans ^ 1); j++) 
   			ans = gcd(ans, b[j]);

   		print_int(ans ? ans : 1);
   		ss[sz++] = '\n';
   	}

   	printf("%s", ss);

   	return 0;                   
}

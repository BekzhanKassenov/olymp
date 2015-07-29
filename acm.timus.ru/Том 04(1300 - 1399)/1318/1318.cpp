#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

struct nmb {
 	unsigned int a[4];

 	nmb() {}

 	void read() {
 		scanf("%u%u%u%u", &a[0], &a[1], &a[2], &a[3]);
 	}

 	int operator ^ (const nmb& n) const {
 		double res = 0;

 		for (int i = 3; i >= 0; i--) {
 			if (a[i] ^ n.a[i]) {
 				res += (log(a[i] ^ n.a[i]) + 32.0 * i * (log(2))) / log(10);
 			}
 		}	

 		return (int)res;
 	}

} a[5010];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		a[i].read();

	int ans = 0;

	double kt = clock();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += a[i] ^ a[j];
		}
	}

	cout << (int)ans;	

	cerr << endl << ((clock() - kt) / CLOCKS_PER_SEC);

	return 0;
}

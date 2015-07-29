#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0)
		return a + b;

	return (gcd(b % a, a));	
}

int main() {
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
 	#endif

 	int a, b, n;

 	cin >> a >> b >> n;

 	int g = gcd(a, b);

 	n /= g;
 	a /= g;
 	b /= g;

 	int ansx = 0, ansy = 0;

 	if (a < b) {
 		for (int y = 0; y <= n / b; y++) {
 			int x = (n - y * b) / a;

 			int cur = n - a * x - b * y;

 			if (cur == 0) {
 				cout << x << ' ' << y << endl;
 				return 0;
 			}

 			if (cur >= 0 && cur < n - ansx * a - ansy * b) {
 				ansx = x;
 				ansy = y;
 			}
 		}
 	} else {
 		for (int x = 0; x <= n / a; x++) {
 			int y = (n - a * x) / b;

 			int cur = n - a * x - b * y;

 			if (cur == 0) {
 				cout << x << ' ' << y << endl;
 				return 0;
 			}

 			if (cur >= 0 && cur < n - ansx * a - ansy * b) {
 				ansx = x;
 				ansy = y;
 			}
 	   	}
 	}

 	cout << ansx << ' ' << ansy << endl;

 	return 0;

}

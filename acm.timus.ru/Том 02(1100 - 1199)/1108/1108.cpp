#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) {
	while (a && b) {
		a %= b;
		swap(a, b);
	}

	return a + b;
}

ll lcm(ll a, ll b) {
	return (a / gcd(a, b) * b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	
	int n;

	cin >> n;

	ll new_den = 2;

	ll num = 0, den = 1;

	for (int i = 0; i < n; i++) {
		bool flag = false;

		do {
		 	ll com_den = lcm(new_den, den);

		 	ll new_num = num * (com_den / den) + 1 * (com_den / new_den);


		 	if (new_num < com_den) {
		 		num = new_num;
		 		den = com_den;
		 		break;
		 	}

		 	new_den++;

		} while (!flag);

		cout << new_den << endl;
	}
	
	return 0;
}


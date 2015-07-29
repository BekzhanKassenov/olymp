#include <iostream>
#include <cstdio>

using namespace std;

int myAbs(int n) {
	return ((n ^ (n >> 31)) - (n >> 31));
}

int gcd(int a, int b) {
	return ((!a || !b) ? a + b : gcd(b % a, a));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y, _x, _y;

	cin >> x >> y >> _x >> _y;

	cout << gcd(myAbs(x - _x), myAbs(y - _y)) + 1;

	return 0;
}
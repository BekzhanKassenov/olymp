#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return ((!a || !b) ? a + b : gcd(b % a, a));
}

ll lcm(ll a, ll b) {
	return (a / gcd(a, b) * b);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll a, b;
	cin >> a >> b;
	cout << lcm(a, b);
}

/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int gcd(int a, int b) {
	if (!a || !b)
		return a + b;

	return gcd(b % a, a);
}

int lcm(int x, int y) {
	int i = y + 1, j = x;

	while (i * x != j * y) {
		if (i * x < j * y)
			i++;
		else
			j++;	
	}

	return i * x - y * x;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b, x, y;

	cin >> x >> y >> a >> b;

	cout << lcm(x, y) << endl;

	int l = lcm(x, y);

	cout << (b / l - a / l + (a % l == 0));

	return 0;
}

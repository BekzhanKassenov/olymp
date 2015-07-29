/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long gcd(long long a, long long b) {
 	while (a && b) {
 	 	a %= b;
 	 	swap(a, b);
 	}

 	return a + b;
}

struct Rational {
	long long p, q;
	bool dir; // 1 - clockwise

	Rational() : p(0), q(1), dir(0) { }

	Rational(long long p, long long q) : p(p), q(q), dir(0) {
		long long g = gcd(this->p, this->q);
		this->p /= g;
		this->q /= g;
	}

	Rational operator / (const Rational r) const {
	 	return Rational(p * r.q, q * r.p);
	}

	void print() {
		if (p == 0) {
		 	puts("not moving");
		 	return;
		}

	 	if (q == 1)
	 		printf("%lld", p);
	 	else
	 		printf("%lld/%lld", p, q);

	 	if (dir)
	 		puts("  clockwise");
	 	else
	 		puts(" counterclockwise");	
	}
};

Rational speed[MAXN];
int x[MAXN], y[MAXN], r[MAXN];
int n, T;
queue <int> q;

bool update(int v, int to) {
	if (speed[to].p != 0)
		return false;

 	long long dist = sqr(x[v] - x[to]) + sqr(y[v] - y[to]);

 	Rational temp(r[to], r[v]);
 		
 	if (dist == sqr(r[v] + r[to])) {
 		speed[to] = speed[v] / temp;
		speed[to].dir = speed[v].dir ^ 1;
 		return true;
 	}
 	
 	if (dist == sqr(r[v] - r[to])) {
 		speed[to] = speed[v] / temp;
 		speed[to].dir = speed[v].dir;
 		return true;
 	}

 	speed[to].q = 1;
   	return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
		 	scanf("%d%d%d", &x[i], &y[i], &r[i]);
			speed[i].p = 0;
		 	speed[i].q = 1;
		}

		speed[0].p = 1;
		speed[0].q = 1;
		speed[0].dir = 1;

		q.push(0);

		while (!q.empty()) {
		 	int v = q.front();
		 	q.pop();

		 	for (int to = 0; to < n; to++) {
		 	 	if (update(v, to)) {
		 	 	 	q.push(to);
		 	 	}
		 	}
		}

		for (int i = 0; i < n; i++) {
		 	speed[i].print();
		}
    }

    return 0;
}

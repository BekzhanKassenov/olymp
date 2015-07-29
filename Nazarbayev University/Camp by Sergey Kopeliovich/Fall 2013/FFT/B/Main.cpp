#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <complex>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct my_complex {
private:
 	double x, y;

public:
 	my_complex() : x(0), y(0) {}

 	my_complex(double x, double y) : x(x), y(y) {}

 	my_complex(const my_complex& a) {
 		*this = a;
 	}

 	my_complex(int a) : x(a + .0), y(0) {}

 	my_complex(double a) : x(a), y(0) {}

 	my_complex operator + (const my_complex& a) const {
 		return my_complex(x + a.x, y + a.y);
 	}

 	my_complex operator * (const my_complex& a) const {
 		return my_complex(x * a.x - y * a.y, y * a.x + x * a.y);
 	}

 	void operator /= (double a) {
 		x /= a;
 		y /= a;
 	}

 	void operator *= (const my_complex& a) {
 		double tx = x * a.x - y * a.y;
 		double ty = y * a.x + x * a.y;
 		x = tx, y = ty;
 	}

 	double& real() {
 		return x;
 	}

 	double& imag() {
 		return y;
 	}
};

typedef my_complex nmb;
vector <nmb> prec;
const double PI = acos(-1.0);
const char alph[] = "ACGT";
int cnt[1000000], n;

void fft(nmb* P, int len) {
	if (len == 1)
		return;

	int nlen = len >> 1;

	nmb A[nlen], B[nlen];

	for (int i = 0; i < len; i += 2) {
		A[i >> 1] = P[i];
		B[i >> 1] = P[i + 1];
	}

	fft(A, nlen);
	fft(B, nlen);

	for (int i = 0; i < len; i++) 
		P[i] = A[i % nlen] + prec[i * (n / len)] * B[i % nlen];
}

int main() {
	freopen("robots.in", "r", stdin);
	freopen("robots.out", "w", stdout);

	ios_base :: sync_with_stdio(false);

	int len;
	cin >> len;

	string s, t;
	cin >> s >> t;

	reverse(all(t));
	s += s;

	n = 1;
	while (n < len)
		n <<= 1;
	n <<= 1;

	prec.resize(n);

	double angle = 2.0 * PI / (n + .0);
	
	for (int i = 0; i < n; i++)
		prec[i] = nmb(cos(angle * i), sin(angle * i));

	nmb a[300000], b[300000];

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++)
			if (i < (len << 1) && alph[k] == s[i])
				a[i] = nmb(1);
			else
				a[i] = nmb();

		for (int i = 0; i < n; i++)
			if (i < n && alph[k] == t[i])
				b[i] = nmb(1);
			else
				b[i] = nmb();

		fft(a, n);
		fft(b, n);
		
		for (int i = 0; i < n; i++)
			a[i] *= b[i];

		fft(a, n);
		reverse(a + 1, a + n);

		for (int i = 0; i < n; i++)
			cnt[i] += (int)(a[i].real() / (n + .0) + .5);
	}

	int pos = 0;

	for (int i = 1; i < n; i++)
		if (cnt[i] > cnt[pos]) 
			pos = i;

	cout << cnt[pos] << ' ' << pos + 1;

	return 0;
}

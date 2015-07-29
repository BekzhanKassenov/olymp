/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "frame"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	double  R, a, b, c, p, P, d, r;
	
	cin >> a >> b >> c >> d;
	
	P = a + b + c;
	P /= 2.0;
	
	R = sqrt((P-a)*(P-c)/P*(P-b));
	
	r = R - d;
	p = P * (R - d) / R;
	
	printf("%.9lf", sqrt((P-a)*(P-c)*P*(P-b)) - p * r);
	
	return 0;
}

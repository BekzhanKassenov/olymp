/****************************************
**         Solution by NU #2           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "bet"

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

int calc(int A, int C, int r, int g, int b) {
	return A * (sqr(r) + sqr(g) + sqr(b)) + C * (min(min(r, g), b));
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int t, a, c, r, g, b;

    cin >> t;

    while (t--) {
    	cin >> a >> c >> r >> g >> b;

    	int red   = calc(a, c, r + 1, g,     b    );
    	int green = calc(a, c, r,     g + 1, b    );
    	int blue  = calc(a, c, r,     g,     b + 1);

    	int mx = max(max(red, blue), green);

    	if (mx == red)
    		cout << "RED";
    	else if (mx == green)
    		cout << "GREEN";
    	else
    		cout << "BLUE";

    	cout << endl;	
    }

	return 0;
}

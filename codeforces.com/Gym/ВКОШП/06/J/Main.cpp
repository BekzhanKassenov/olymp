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
#define File "windows"

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

int count_tabs(const string& s) {
	int ans = 0;

	for (int pos = 3; pos < (int)s.size(); pos++)
		ans += (s[pos] == '+');

	return ans;
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;
	cin >> n;

	vector <string> a;

	string s;
	getline(cin, s);

	for (int i = 0; i < n; i++) {
		getline(cin, s);

		if (s.substr(0, 3) == "Run") {
			s = s.substr(4);
			a.push_back(s);
		} else {
			int t = count_tabs(s);
			t %= a.size();
			t = a.size() - t - 1;
			for (; t < (int)a.size() - 1; t++)
				swap(a[t], a[t + 1]);
		}
		cout << a.back() << endl;
	}

	return 0;
}

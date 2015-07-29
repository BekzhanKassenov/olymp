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
#define File "number"

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

bool cmp(const string& a, const string& b) {
	string tmp1 = a + b;
	string tmp2 = b + a;

	for (size_t i = 0; i < tmp1.size(); i++)
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] < tmp2[i]);

	return false;
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	string tmp;
	vector <string> a;

	while (cin >> tmp)
		a.push_back(tmp);

   	sort(all(a), cmp);

   	for (int i = a.size() - 1; i >= 0; i--)
   		cout << a[i];

	return 0;
}

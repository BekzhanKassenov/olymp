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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> vec;
map <int, int> curpos;
int a[MAXN], b[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

	scanf("%d", &n);

	vec.reserve(2 * n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		vec.push_back(a[i]);
		vec.push_back(b[i]);
	}

	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	curpos[vec[0]] = 0;

	for (size_t i = 1; i < vec.size(); i++) {
		curpos[vec[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		int posa = curpos[a[i]];
		int posb = curpos[b[i]];

		printf("%d\n", abs(vec[posa] - vec[posb]));
		swap(curpos[a[i]], curpos[b[i]]);
	}

    return 0;
}

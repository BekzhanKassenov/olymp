/****************************************
**     Solution by Bekzhan Kassenov    **
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

int n, a[MAXN], b[MAXN];
int t[MAXN];
int coeff[MAXN];

void update(int pos) {
	for (int i = pos; i < n; i |= i + 1)
		t[i]++;
}

int sum(int pos) {
	if (pos < 0)
		return 0;

	int result = 0;
 	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
 		result += t[i];

	return result;
}

struct Tree {
  	int tree[4 * MAXN];

  	void build(int v, int l, int r) {
  	    if (l == r) {
  	     	tree[v] = 1;
  	    } else {
  	     	int mid = (l + r) / 2;
  	     	build(2 * v, l, mid);
  	     	build(2 * v + 1, mid + 1, r);

  	     	tree[v] = tree[2 * v] + tree[2 * v + 1];
  	    }
  	}

  	int get_kth(int v, int l, int r, int num) {
  	 	if (l == r)
  	 		return l;

  	 	int mid = (l + r) / 2;
  	 	if (tree[2 * v + 1] >= num) {
  	 		return get_kth(2 * v + 1, mid + 1, r, num);
		}

		return get_kth(2 * v, l, mid, num - tree[2 * v + 1]);
  	}

  	void erase(int v, int l, int r, int pos) {
  	 	if (l > r || pos < l || pos > r)
  	 		return;

  	 	if (l == r) {
  	 		tree[v] = 0;
  	 	} else {
			int mid = (l + r) / 2;
			erase(2 * v, l, mid, pos);
			erase(2 * v + 1, mid + 1, r, pos);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
  	 	}
  	}
};

Tree tree;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &b[i]);
	}
	
	for (int i = 0; i < n; i++) {
		coeff[i] += a[i] - sum(a[i] - 1);
		
		update(a[i]);
	}

	memset(t, 0, sizeof t);

	for (int i = 0; i < n; i++) {
		coeff[i] += b[i] - sum(b[i] - 1);
		
		update(b[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
	 	int carry = coeff[i] / (n - i);
	 	coeff[i] %= n - i;

	 	if (i > 0)
	 		coeff[i - 1] += carry;
	}

	tree.build(1, 0, n - 1);
	vector <int> result(n);

	for (int i = n - 1; i >= 0; i--) {
		int num = tree.get_kth(1, 0, n - 1, coeff[i] + 1);
		tree.erase(1, 0, n - 1, num);
		result[i] = num;
	}

	for (size_t i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}

    return 0;
}

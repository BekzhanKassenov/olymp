#include <iterator>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

const int maxn = 15010;
const int maxcoord = 32010;

vector <int> a[maxcoord];
PII b[maxn];
int ans[maxn], n;

struct Tree {
 	vector <int> t[maxcoord * 4];

 	Tree() {
 		build(1, 0, maxcoord - 1);
 	}

 	void build(int v, int l, int r) {
 		if (l > r)
 			return;

 		if (l == r) {
 			t[v] = a[l];
 			return;
 		}

 		int mid = (l + r) >> 1;

 		build(v << 1, l, mid);
 		build((v << 1) + 1, mid + 1, r);

 		merge(all(t[v << 1]), all(t[(v << 1) + 1]), back_inserter(t[v]));
 	}
 	    
 	int level(int x, int y) {
 		return level(1, 0, maxcoord - 1, x, y);
 	}

 	int level(int v, int l, int r, int x, int y) {
 		if (l > r || x < l)
 			return 0;

 		if (x >= r) {
 			return max(upper_bound(all(t[v]), y) - t[v].begin() - 1, 0);
 		}

 		int mid = (l + r) >> 1;

 		return (level(v << 1, l, mid, x, y) + level((v << 1) + 1, mid + 1, r, x, y));
 	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &b[i].F, &b[i].S);
		a[b[i].F].push_back(b[i].S);
	}

	for (int i = 0; i < maxcoord; i++) {
		if (!a[i].empty())
			sort(all(a[i]));
	}

	Tree tree;

	for (int i = 0; i < n; i++) {
		ans[tree.level(b[i].F, b[i].S)]++;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);

	return 0;
}
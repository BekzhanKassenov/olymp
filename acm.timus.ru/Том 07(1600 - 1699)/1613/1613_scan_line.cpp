#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 100000;

struct query {
 	int l, val, nmb;

 	query() {}

 	query(int l, int val, int nmb) : l(l), val(val), nmb(nmb) {}
};

struct st {
 	int val;

 	vector <query> q;
} a[maxn];

bool ans[maxn];
int n, m, l, r, val;
map <int, int> Map;
query tmp;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	scanf("%d", &n);

  	for (int i = 0; i < n; i++)
  		scanf("%d", &a[i].val);
	
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &l, &r, &val);
		a[--r].q.push_back(query(l - 1, val, i));
	}

	for (int i = 0; i < n; i++) {
		Map[a[i].val] = i;

		for (size_t j = 0; j < a[i].q.size(); j++) {
			tmp = a[i].q[j];

			if (Map.count(tmp.val))
				ans[tmp.nmb] = (Map[tmp.val] >= tmp.l) ? true : false;
			else
				ans[tmp.nmb] = false;	
		}
	}

	for (int i = 0; i < m; i++)
		putchar(ans[i] ? '1' : '0');

	return 0;
}
                                     	 
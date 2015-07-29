#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct prob {
 	string a, b, c;

 	prob() {}

 	prob(string p, string q, string r) {
 		a = min(min(p, q), r);
 		c = max(max(p, q), r);

 		bool flag1 = (a == p || c == p);
 		bool flag2 = (a == q || c == q);

 		if (!flag1)
 			b = p;
 		else
 			if (!flag2)
 				b = q;
 			else
 				b = r;	
 	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <prob> a(n), tmp(n);

	string p, q, r;

	for (int i = 0; i < n; i++) {
		cin >> p >> q >> r;

		a[i] = prob(p, q, r);
	}

	int t;

	for (int i = 0; i < n; i++) {
		cin >> t;
		tmp[i] = a[t - 1];
	}

	vector <string> ans;
	a = tmp;

	ans.push_back(a[0].a);

	for (int i = 1; i < n; i++) {
		if (a[i].a > ans.back()) {
			ans.push_back(a[i].a);
			continue;
		}
		if (a[i].b > ans.back()) {
			ans.push_back(a[i].b);
			continue;
		}

		if (a[i].c > ans.back()) {
			ans.push_back(a[i].c);
			continue;
		}

		puts("IMPOSSIBLE");
		return 0;
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;


}

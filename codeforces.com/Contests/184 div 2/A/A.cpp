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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool check(int a, int b) {
 	for (int i = 0; i < 3; i++) {
 	 	if (a % 10 && b % 10)
 	 		return false;

 	 	a /= 10;
 	 	b /= 10;
 	}

 	return true;
}

int n, x;
vector <int> temp, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &x);

	 	if (x == 0) {
	 		ans.push_back(x);
	 	} else {
	 		temp.push_back(x);
	 	}
	}

	bool found = false;
	for (size_t i = 0; i < temp.size() && !found; i++) {
	 	for (size_t j = i + 1; j < temp.size() && !found; j++) {
	 	 	for (size_t k = j + 1; k < temp.size() && !found; k++) {
				if (check(temp[i], temp[j]) && check(temp[i], temp[k]) && check(temp[j], temp[k])) {
				 	ans.push_back(temp[i]);
				 	ans.push_back(temp[j]);
				 	ans.push_back(temp[k]);
				 	found = true;
				}
	 	 	}
	 	}
	}

	for (size_t i = 0; i < temp.size() && !found; i++) {
	 	for (size_t j = i + 1; j < temp.size() && !found; j++) {
			if (check(temp[i], temp[j])) {
			 	ans.push_back(temp[i]);
			 	ans.push_back(temp[j]);
			 	found = true;
			}
	 	}
	}

	if (!found && !temp.empty()) {
	 	ans.push_back(temp[0]);
	}

	printf("%d\n", ans.size());
	for (size_t i = 0; i < ans.size(); i++) {
	    printf("%d ", ans[i]);
	}

	puts("");

	return 0;
}
                                       	
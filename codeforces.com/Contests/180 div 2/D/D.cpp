/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define MOD (1000 * 1000 * 1000 + 7)

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
T sqr(T n) {
	return (n * n);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

template <typename T>
T mmin(T a, T b) {
	return (a < b ? a : b);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	map <int, int> Map1, Map2;

	int n, m, k;

	scanf("%d%d%d", &n, &m, &k);

	if (n > m) {
		cout << "YES";
		return 0;
	}

	int x;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		Map1[x]++;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		Map2[x]++;
	}

	for (map <int, int> :: iterator it = Map1.begin(); it != Map1.end(); it++) {
		if (Map2.count(it -> F)) {
			int k = mmin(it -> S, Map2[it -> F]);

			it -> S -= k;
			Map2[it -> F] -= k;
		}
	}

	vector <int> v1, v2;

	for (map <int, int> :: iterator it = Map1.begin(); it != Map1.end(); it++) {
		for (int j = 0; j < it -> S; j++)
			v1.push_back(it -> F);
	}


	for (map <int, int> :: iterator it = Map2.begin(); it != Map2.end(); it++) {
		for (int j = 0; j < it -> S; j++)
			v2.push_back(it -> F);
	}

	for (int i = 0; i < (int)v1.size(); i++) {
		int k = (upper_bound(v2.begin(), v2.end(), v1[i]) - v2.begin());

		int cnt1 = v1.size() - i;
		int cnt2 = v2.size() - k;

		if (i > k)
			cnt1 += i - k;


		if (cnt1 > cnt2) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}

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
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	multiset <int> s;

	int x, sum = 0;

	for (int i = 0; i < 2 * n - 1; i++) {
	 	cin >> x;

	 	s.insert(x);

	 	sum += x;
	}

	vector <int> ans;

	ans.push_back(sum);

	for (int i = 0; i < n; i++) {
	 	sum = 0;

	 	for (int j = 0; j < n; j++) {
	 		int tmp = (*s.begin());

	 		tmp *= -1;

	 		s.erase(s.begin());
	 		s.insert(tmp);
	 	}

	 	for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
	 		{sum += *it;  cout << *it << ' ';}
	 		cout << endl;

	 	ans.push_back(sum);
	 	cout << sum << endl;
	}

	cout << *max_element(all(ans));

	return 0;
}

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

int cnt[26];
string s;
int n;

bool can(int z) {
	int len = 0;

	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0) {
			int c = (cnt[i] / z) + (cnt[i] % z != 0);
			len += c;
		}
	}

	return (len <= n);
}

void make(string& res, int z) {
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0) {
			int c = (cnt[i] / z) + (cnt[i] % z != 0);

			for (int j = 0; j < c; j++)
				res += i + 'a';
		}
	}
	int len = res.size();

	while (len < n) {
		res += 'a';
		len++;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	getline(cin, s);

	cin >> n;

	for (size_t i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;

	for (int i = 1; i <= 1000; i++) {
		if (can(i)) {
			string res;

			make(res, i);

			cout << i << endl << res;
			return 0;
		}
	}

	cout << -1;
   	
	return 0;
}

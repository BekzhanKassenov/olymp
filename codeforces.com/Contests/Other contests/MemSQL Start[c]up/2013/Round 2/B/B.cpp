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
vector <vector <int> > dp;

int solve(int l, int r) {
	if (l > r)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	if (l == r)
		return (dp[l][r] = 1);

	if (s[l] == s[r])
		dp[l][r] = solve(l + 1, r - 1) + 2;
	else
		dp[l][r] = max(solve(l + 1, r), solve(l, r - 1));	

	return dp[l][r];
}

void create(string& res, int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		res += s[l];
		return;
	}	

	if (s[l] == s[r]) {
		res += s[l];
		create(res, l + 1, r - 1);
	} else {
		if (dp[l][r] == dp[l + 1][r])
			create(res, l + 1, r);
		else
			create(res, l, r - 1);	
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	getline(cin, s);

	for (size_t i = 0; i < s.size(); i++) 
		cnt[s[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		if (cnt[i] >= 100) {
		 	for (int j = 0; j < 100; j++)
		 		cout << (char)('a' + i);
		 		return 0;
		}

  	int len = s.size();
  	dp.resize(len, vector <int> (len, -1));

  	solve(0, len - 1);

  	string res;
  	create(res, 0, len - 1);

  	int pos = res.size() - 1;

  	if (dp[0][len - 1] % 2 == 1)
  		pos--;

  	if (res.size() + pos + 1 <= 100) {
  		cout << res;

  		for (int i = pos; i >= 0; i--)
  			cout << res[i];

  		return 0;
  	}

  	for (int i = 0; i < 50; i++)
  		cout << res[i];

  	for (int i = 49; i >= 0; i--)
  		cout << res[i];	
		
	return 0;
}

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
T min(T a, T b) {
	return (a < b ? a : b);
}

bool used[3000010];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	string s, t;

	cin >> s >> t;

	int cnt[2], c = 0;

	cnt[0] = cnt[1] = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == '1' && t[i] == '1')
			c++;
	}

	cnt[0] = (c + 1) / 2;
	cnt[1] = c / 2;

	int cc[2];

	cc[0] = cc[1] = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == '1' && t[i] == '0')
			cc[0]++;

		if (s[i] == '0' && t[i] == '1')
			cc[1]++;	
	}

	int wh = c % 2;

	while (true) {
		if (cc[0] == 0 && cc[1] == 0)
			break;

		if (cc[wh ^ 1] != 0) 
			cc[wh ^ 1]--;
		else {
		 	cc[wh]--;
		 	cnt[wh]++;
		}	

		wh ^= 1;
	}

	if (cnt[0] > cnt[1])
		cout << "First";
	else
		if (cnt[0] == cnt[1])
			cout << "Draw";
		else
			cout << "Second";	

	return 0;
}

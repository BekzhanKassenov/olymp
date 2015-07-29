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
#define all(x) (x).begin(),(x).end()

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

bool used[26] = {0};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	getline(cin, s);

	long long tmp = 1;

	int flag = 0;

	if (s[0] == '?') 
		tmp = 9;

   	if (s[0] >= 'A' && s[0] <= 'J') {
   		tmp = 9;
   		flag = 1;
   		used[s[0] - 'A'] = true;
   	}

   	int cnt = 0;

   	for (int i = 1; i < (int)s.size(); i++) {
   		if (s[i] == '?')
   			cnt++;

   		if (s[i] >= 'A' && s[i] <= 'J')
   			used[s[i] - 'A'] = true;
   	}

   	int n = 10 - flag;
   	int k = 0;

   	for (int i = 0; i < 26; i++)
   		k += used[i];

   	k -= flag;

   	if (k > 0) {
   		for (int i = 2; i <= n; i++)
   			tmp *= i;

		for (int i = 2; i <= (n - k); i++)
			tmp /= i;
	}
   	
   	cout << tmp;

   	for (int i = 0; i < cnt; i++)
   		cout << '0';

	return 0;
}

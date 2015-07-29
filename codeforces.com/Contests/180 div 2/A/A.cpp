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

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	string s;

	cin >> s;

	int pos1 = -1, pos = -1;

	for (int i = 0; i < n; i++)
		if (s[i] != '.') {
			pos = i;
			break;
		}

	for (int i = n - 1; i >= 0; i--)
		if (s[i] != '.') {
			pos1 = i;
			break;
		}

	if (s[pos] == 'L') {
		cout << pos1 + 1 << ' ' << pos;	
		return 0;
	}

	if (s[pos1] == 'R') {
		cout << pos + 1 << ' ' << pos1 + 2;
		return 0;
	}

	for (int i = 0; i < n - 1; i++)
		if (s[i] == 'R' && s[i + 1] == 'L') {
		 	pos1 = i;
		 	break;
	   	}       

	cout << pos + 1 << ' ' << pos1 + 1;
	return 0;
}

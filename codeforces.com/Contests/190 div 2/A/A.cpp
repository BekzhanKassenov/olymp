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

int cnt[2];

stringstream ss;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> cnt[0] >> cnt[1];

	int ans = 1;

	int a = 0, b = 0;

	ss << 1 << ' ' << 1 << endl;

	int pos;

	if (a > b)
		pos = a;
	else
		pos = b;

	while (true) {
		if (pos == 0) {
		 	if (a < cnt[0] - 1)
		 		a++;
		 	else {
		 		pos ^= 1;
		 		if (b < cnt[1] - 1)
		 			b++;
		 		else
		 			break;	
		 	}
		} else {
			if (b < cnt[1] - 1) 
				b++;
			else {
			 	pos ^= 1;

			 	if (a < cnt[0] - 1)
			 		a++;
			 	else
			 		break;	
			}	
		}

		ans ++;
		pos ^= 1;

		ss << a + 1 << ' ' << b + 1 << endl;
	}	

	cout << ans << endl << ss.str();

	return 0;
}

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

const int maxn = 100000 + 50;
int a[maxn], n, test[maxn][35];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int i;

	for (i = 30; i >= 0; i--) {
		int tmp = (1 << i);

		for (int j = 1; j <= n; j++) {
			if (tmp & (a[j]))
				test[j][i] = 1;
		}
	}
	
	for (i = 30; i >= 0; i--) {
		int j, tmp = 0;

		for (j = 1; j <= n; j++) {
			if (test[j][i]) {
				tmp = a[j];
				break;
			}
		}

		for (;j <= n; j++) {
			if (test[j][i]) {
				tmp &= a[j];
				int tst = (1 << i) - 1;

				if (tmp)
					if ((tmp & tst) == 0)
						break;
			}
		}
	}

 	if (i == -1) {
 	cout << n << endl;

	for (int j = 1; j <= n; j++)
		cout << a[j] << ' ';	
   	}

   	int sum = 0;

   	for (int k = 1; k <= n; k++)
   		if (test[k][i])
   			sum++;

  	cout << sum << endl;

  	int p;

  	for (p = 1; p <= n; p++)
  		if (test[p][i]) {
  			cout << a[p];
  			break;
  		}

   	for (p++; p <= n; p++)
   		if (test[p][i])
   			cout << a[p];
}

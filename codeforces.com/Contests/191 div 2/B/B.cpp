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
#define all (x) (x).begin(), (x).end()

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

const int lim = (int)1e7;

vector <int> pr;
bool prime[lim];

void build() {
	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = 0;

	for (int i = 2; i < (int)1e7; i++) {
		if (prime[i]) {
			pr.push_back(i);

			if (i * 1ll * i < lim) {
			  	for (int j = i * i; j < lim; j += i)
			  		prime[j] = false;
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	build();

	cin >> n;

	for (int i = 0; i < n; i++)
		cout << pr[i] << ' ';


	return 0;
}

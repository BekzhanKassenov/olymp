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

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	vector <int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		a[i] = i;
		b[i] = i;
	}

	do {
		do {
			vector <int> c(n);

			for (int i = 0; i < n; i++)
				c[i] = (a[i] + b[i]) % n;

			sort(c.begin(), c.end());

			bool flag = true;

			for (int i = 0; i < n; i++)
				if (c[i] != i)
					flag = false;

		   	if (flag) {
		   		for (int i = 0; i < n; i++)
		   			cout << a[i] << ' ';

		   		cout << endl;
		   			
		   		for (int i = 0; i < n; i++)
		   			cout << b[i] << ' ';


		   		cout << endl;
		   			
		   		for (int i = 0; i < n; i++)
		   			cout << (a[i] + b[i]) % n << ' ';	

		   		return 0;	
		   	}
		} while (next_permutation(b.begin(), b.end()));

	} while (next_permutation(a.begin(), a.end()));

	return 0;
}
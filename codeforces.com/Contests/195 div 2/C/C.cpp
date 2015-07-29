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

const int maxn = 100000;
int a[maxn], res, n;
vector <int> nmb[50];

void make(int n) {
	int st = n;

	int cnt = 0;

	while (n) {
		if (n & 1) 
			nmb[cnt].push_back(st);
		
		n >>= 1;
		
		cnt++;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		make(a[i]);
	}

	int ans = 0;

	for (int i = 0; i < 50; i++) {
		if (!nmb[i].empty()) {
			int tmp = nmb[i][0];

			for (int j = 1; j < (int)nmb[i].size(); j++)
				tmp = tmp & nmb[i][j];

			if (tmp > 0 && tmp % (1 << i) == 0) 
				ans = i;
	  	}
	}

	cout << nmb[ans].size() << endl;
	
	for (size_t i = 0; i < nmb[ans].size(); i++)
		cout << nmb[ans][i] << ' ';

	return 0;
}

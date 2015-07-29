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
#define INF (ll)(2e10)
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

int n, d;

ll a[110], g[110][110];

pair <ll, ll> c[110];

bool check(int val) {
	queue <int> q;

	vector <ll> dist(n, -INF);

	dist[0] = val;

	q.push(0);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 1; i < n; i++) {
			if (g[v][i] <= dist[v] && v != i)
				if (dist[i] < dist[v] - g[v][i] + a[i]) {
					q.push(i);
					dist[i] = dist[v] - g[v][i] + a[i];
				}
		}
	}

	return (dist[n - 1] > (-INF));
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> d;

	for (int i = 1; i < n - 1; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> c[i].F >> c[i].S;

   	for (int i = 0; i < n; i++) 
   		for (int j = 0; j < n; j++) 
   		 	g[i][j] = (abs(c[i].F - c[j].F) + abs(c[i].S - c[j].S)) * d;


 	int l = 0, r = (int)1e9;

 	while (l <= r) {
 		int m = (l + r) >> 1;

 		if (check(m))
 			r = m - 1;
 		else
 			l = m + 1;	
 	}

	cout << r + 1 << endl;
	
	return 0;
}

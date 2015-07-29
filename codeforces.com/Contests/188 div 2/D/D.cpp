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
#include <conio.h>
#include <windows.h>

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

const int sz = 500;
               
int a[sz][sz];
bool inque[sz][sz];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int emulate() {
	int cnt = 0;

	queue <PII> q;

	q.push(MP(sz / 2, sz / 2));
	inque[sz / 2][sz / 2] = true;

	while (!q.empty()) {
		int x = q.front().F;
		int y = q.front().S;

		q.pop();

		inque[x][y] = false;

		if (a[x][y] < 4)
			continue;

		int tmp = a[x][y] / 4;
		a[x][y] %= 4;

		for (int i = 0; i < 4; i++) {
			int tmpx = x + dx[i];
			int tmpy = y + dy[i];

			a[tmpx][tmpy] += tmp;

			if (a[tmpx][tmpy] >= 4 && !inque[tmpx][tmpy]) {
				q.push(MP(tmpx, tmpy));
				inque[tmpx][tmpy] = true;
			}
		}
		cnt++;
	}

	return cnt;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	a[sz / 2][sz / 2] = n;

	if (n >= 4)
		emulate(); 

	int x, y;

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;

		x += sz / 2, y += sz / 2;

		if (x >= 0 && x < sz && y >= 0 && y < sz)
			cout << a[x][y];
		else
			cout << 0;

		cout << endl;	
	}

	return 0;
}

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

int odn[110], n;
vector <bool> used;
int mexx[110][110][110];
bool u[110][2];

void get(int& l, int& low, int pos, bool us[110][2], int j) {
	while (pos >= 0 && us[pos][j])
		pos--;

	pos++;
	low = pos;

	while (pos < 110 && us[pos][j]) {
		pos++;
		l++;
	}
}

void get_comp(int &l, int& r, int& sm, bool us[110][2], int pos) {
	int l1, l2;

	get(l, l1, pos, us, 0);

	bool flag = false;

	for (int i = 0; i < l && !flag; i++)
		if (us[l1 + i][1]) {
			get(r, l2, l1 + i, us, 1);
			flag = true;
		}

   	if (flag) 
   		sm = l2 - l1;
   	else
   		r = 0, sm = 0;
}

int get_mexx(int l, int r, int sm) {
	if (sm >= 0 && mexx[l][r][sm] != -1)	
		return mexx[l][r][sm];

	if (sm < 0 && mexx[r][l][-sm] != -1)
		return mexx[r][l][-sm];

	if (l == 0)
		return odn[r];

	if (r == 0)
		return odn[l];

   	used.assign(n, 0);

   	bool us[110][2];

   	for (int i = 0; i < l; i++)
   		us[i][0] = true;

   	for (int i = 0; i < r; i++)
   		us[i + sm][1] = true;


}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	odn[0] = 0;
	odn[1] = 1;
	memset(mexx, -1, sizeof mexx);

	for (int i = 2; i <= n; i++) {
		used.assign(n, 0);

		for (int j = 2; j <= i - 1; j++) {
		    used[odn[j - 2] ^ odn[i - j - 1]] = true;
		}

		for (int j = 0; j < n; j++)
			if (!used[j]) {
				odn[i] = j;
				break;
			}
	}

	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <bitset>

using namespace std;

const int MAXN = 105;
const int lim = 55500;
const int p = 131;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
string a[MAXN];
int len[MAXN];
long long pp[55500];
long long hh[MAXN][55500];
bool pref[MAXN][lim], suf[MAXN][lim];
bool dp[MAXN][lim];
bool used[MAXN][lim];
bool ans = false;

long long get_hh(int s, int l, int r) {
	long long res = hh[s][r] % mod;
	if (l > 0)
		res = (res - hh[s][l - 1] + mod) % mod;
	res = (res * pp[50000 - l]) % mod;
	while (res < 0)
		res += mod;
	return res % mod;
}

bool go(int s, int pos) {
	if (used[s][pos])
		return dp[s][pos];
	used[s][pos] = true;
	if (pref[s][pos]) {
		dp[s][pos] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (s == i)
			continue;
		if (len[i] == pos + 1) 
			continue;
		else if (len[i] < pos + 1) {
			if (get_hh(s, pos - len[i] + 1, pos) == get_hh(i, 0, len[i] - 1)) {
				//	prev[i][j] = pref[i][j] | prev[i][j - len[k]];
				if (go(s, pos - len[i]))
					dp[s][pos] = true;
			}
		}
		else {
			if (get_hh(s, 0, pos) == get_hh(i, len[i] - (pos + 1), len[i] - 1)) {
				if (go(i, len[i] - (pos + 1) - 1))
					dp[s][pos] = true;
			}
		}
	}
	return dp[s][pos];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		getline(cin, a[i]);
		len[i] = (int) a[i].length();
	}

	pp[0] = 1;
	for (int i = 1; i <= 55000; i++) {
		pp[i] = pp[i - 1] * p % mod;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < len[i]; j++) {
			hh[i][j] = pp[j] * (a[i][j] - 'a' + 1);
			if (j > 0)
				hh[i][j] = (hh[i][j] + hh[i][j - 1]) % mod;
			hh[i][j] %= mod;
			while (hh[i][j] < 0)
				hh[i][j] += mod;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < len[i]; j++) {
			for (int k = 1; k <= n; k++) {
				if (k == i)
					continue;
				if (len[k] > j + 1)
					continue;
				if (get_hh(i, j - len[k] + 1, j) == get_hh(k, 0, len[k] - 1)) {
					if (len[k] == j + 1)
						pref[i][j] = true;
					else
						pref[i][j] = pref[i][j] | pref[i][j - len[k]];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = len[i] - 1; j >= 0; j--) {
			for (int k = 1; k <= n; k++) {
				if (k == i)
					continue;
				if (len[k] > len[i] - j )
					continue;
				if (get_hh(i, j, j + len[k] - 1) == get_hh(k, 0, len[k] - 1)) {
					if (len[k] == len[i] - j)
						suf[i][j] = true;
					else
						suf[i][j] = suf[i][j] | suf[i][j + len[k]];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (len[i] > 1)
			for (int j = 1; j < len[i]; j++)
				if (suf[i][j] && go(i, j - 1))
					ans = true;

	if (ans)
		puts("YES");
	else
		puts("NO");
	
	return 0;
}


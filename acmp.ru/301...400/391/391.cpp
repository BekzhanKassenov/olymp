#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

bool dp[200][300];
int pr[200][300], c[200][300];

int x, m, l, v;

bool check(const string& s) {
	int res = 0;

	if ((int)s.size() != l)
		return false;

	for (int i = l - 1; i >= 0; i--) {
		res *= x;
		res += (s[i] - '0');
		res %= m;
	}	

	return (res == v);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> x >> m >> l >> v;

	int power = 1;

	for (int i = 0; i < 10; i++) {
		dp[0][i % m] = 1;
		c[0][i % m] = i;
   	}

   	bool found = false;
   	int start = l - 1;

	for (int i = 1; i < l && !found; i++) {
		power *= x;
		power %= m;

		for (int j = 0; j < 10; j++) {
			int cur = (power * j) % m;

			for (int k = 0; k < m; k++) {
				if (dp[i - 1][k]) {
					dp[i][(k + cur) % m] = true;
					 c[i][(k + cur) % m] = j;
					pr[i][(k + cur) % m] = k;
				}
			}
		}

		if (dp[i][v]) {
			start = i;
			found = true;
		}
	}

	/*for (int i = 0; i < l; i++) {
	 	for (int j = 0; j < m; j++)
	 		cout << dp[i][j] << ' ';
	 	
	 	cout << endl;	
	}*/

	if (found) {
		string s;

		int cur = v;

		for (int j = l - 1; j > start; j--)
			s += '0';

		for (int j = start; j >= 0; j--) {
		 	s += c[j][cur] + '0';
		 	cur = pr[j][cur];
		}
		
		reverse(s.begin(), s.end());

		cout << s << endl;

		assert(check(s));
	} else 
	 	cout << "NO SOLUTION" << endl;
	
	return 0;
}

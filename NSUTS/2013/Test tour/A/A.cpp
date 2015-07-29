#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int ans = 0;

	int res = 0;

	if (n >= 1) {
		for (int i = 1; i <= 100; i++) {
			if (i <= n)
				ans += i;
			for (int j = 1; j <= 100; j++) {
				for (int k = 1; k <= 100; k++) {
					for (int l = 1; l <= 100; l++) {
							res += j;
							res *= k;
							res += j;
							res += l * k * (j + 1);
					}
				}
	 		}
	   }
	} else {
		for (int i = 1; i >= -100; i--) {
			if (i >= n)
				ans += i;
			for (int j = 1; j >= -100; j--) {
				for (int k = 1; k >= -100; k--) {
					for (int l = 1; l >= -100; l--) {
							res += j;
							res *= k;
							res += j;
							res += l * k * (j + 1);
					}
				}
			}
		}
	}

	stringstream ss;

	ss << res;

	string str;

	ss >> str;

	str[0] = 'a';

	cout << (ans + (str[0] != 'a'));

	return 0;	
}

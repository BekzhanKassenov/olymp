#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int get_decimal_num(char c) {
	if (isdigit(c))
		return c - '0';

	return (10 + c - 'A');
}

char get_hex_num(int n) {
	if (n >= 0 && n <= 9)
		return (n + '0');

	return (n - 10 + 'A');
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	                                            
	int t;
	cin >> t;

	while (t--) {
		int x, y;
		string s;

		cin >> x >> y >> s;

		long long num = 0;

		for (size_t i = 0; i < s.size(); i++) {
			num *= x;
			num += get_decimal_num(s[i]);
		}

		if (num == 0) {
			cout << 0 << endl;
			continue;
		}

		s.clear();

		while (num) {
			s += get_hex_num(num % y);
			num /= y;
		}

		reverse(s.begin(), s.end());
		
		cout << s << endl;
	}
}

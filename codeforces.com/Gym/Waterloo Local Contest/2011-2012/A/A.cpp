#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int make_number_from_array(int cnt[6]) {
	int res = 0;

	for (int i = 0; i < 6; i++) {
	 	res *= 10;
	 	res += cnt[i];
	}

	return res;
}

void make_array_from_number(int n, int cnt[6]) {
	for (int i = 5; i >= 0; i--) {
		cnt[i] = n % 10;
		n /= 10;
	}
}

map <int, bool> mem;

bool win(int n) {
	int cnt[6];

	if (mem.count(n))
		return mem[n];

	make_array_from_number(n, cnt);

	int sum = 0;

	for (int i = 0; i < 6; i++) {
		sum += (i + 1) * cnt[i];
	}

	if (sum > 31)
		return true;

	
	    //cout << sum << endl;

	bool ans = false;

	for (int i = 0; i < 6; i++) {
		if (cnt[i] < 4) {
			cnt[i]++;
			int new_num = make_number_from_array(cnt);
			ans |= (!win(new_num));
			cnt[i]--;
		}
	}

	mem[n] = ans;

	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int cnt[6];

	string s;

	while (cin >> s) {
		for (int i = 0; i < 6; i++)
			cnt[i] = 0;

		for (size_t i = 0; i < s.size(); i++) {
			cnt[s[i] - '0' - 1]++;
		}	

	   	int nm = make_number_from_array(cnt);
	   	bool ans = win(nm);

	   	int len = s.size();

	   	if ((len % 2 == 1 && ans) || (len % 2 == 0 && !ans)) {
	   		cout << s << ' ' << 'B' << endl;
	   	} else
	   		cout << s << ' ' << 'A' << endl;
	}

	return 0;
}

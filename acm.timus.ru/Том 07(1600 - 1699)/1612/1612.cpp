#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int len;

bool is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

inline string next_word(const string& s, int& pos) {
	while (pos < len && !is_letter(s[pos]))
		pos++;

	string ans;

	while (pos < len && is_letter(s[pos]))
		ans += s[pos++];

	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	int cnt_tram = 0, cnt_trol = 0;

	while (getline(cin, s)) {
		len = s.size();

		int pos = 0;

		while (pos < len) {
			string cur_word = next_word(s, pos);

			if (cur_word == "tram")
				cnt_tram++;

			if (cur_word == "trolleybus")
				cnt_trol++;
	   	}
	}

	if (cnt_tram > cnt_trol)
		cout << "Tram driver";

	if (cnt_tram < cnt_trol)
		cout << "Trolleybus driver";

	if (cnt_tram == cnt_trol)
		cout << "Bus driver";

	return 0;	
}
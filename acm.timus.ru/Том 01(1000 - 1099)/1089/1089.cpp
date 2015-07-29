#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool letter(char c) {
	return (c >= 'a' && c <= 'z');
}

void next_word(const string& s, int &pos, int& l, int& r) {
	int len = s.size();

	while (pos < len && !letter(s[pos]))
		pos++;	

	l = pos;

	while (pos < len && letter(s[pos]))
		pos++;

	r = pos;
}

bool can(const string& s1, const string& s2) {
	int cnt = 0;

	if (s1.length() != s2.length())
		return false;

	for (size_t i = 0; i < s1.length(); i++)	
		cnt += (s1[i] != s2[i]);

	return (cnt == 1);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	string s;

	vector <string> a;

	while (getline(cin, s) && s != "#")
		a.push_back(s);

	int cnt = 0;

	while (getline(cin, s)) {
	 	int pos = 0, l = -1, r = -1;

	 	int len = s.size();

	 	while (pos < len) {
	 		l = -1, r = -1;

	 		next_word(s, pos, l, r);

	 		if (l != -1) {
	 			string tmp = s.substr(l, r - l);

	 			for (size_t i = 0; i < a.size(); i++) {
	 				if (can(a[i], tmp)) {
	 					cnt++;

	 					for (int j = l; j < r; j++) {
	 						s[j] = a[i][j - l];
	 					}

	 					break;
	 				}
	 			}
	 		}
	 	}

	 	cout << s << endl;
	}

	cout << cnt << endl;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

bool cmp(const string& s1, const string& s2) {
	int len1 = s1.size(), len2 = s2.size();

	if (len1 != len2)
		return len1 < len2;

	for (int i = 0; i < len1; i++)
		if (s1[i] != s2[i])
			return s1[i] < s2[i];

	return false;	
}

bool sklei(const string& s1, const string& s2, int pos, string& res) {
	res = s1.substr(0, pos);

	int len1 = s1.size(), len2 = s2.size();

	for (int i = pos; i < min(len1, pos + len2); i++) {
		if (tolower(s1[i]) == tolower(s2[i - pos]))
			res += s2[i - pos];
		else
			return false;
	}

	for (int i = min(len1, pos + len2); i < max(len1, pos + len2); i++) {
		if (i < len1)
			res += s1[i];
		else
			res += s2[i - pos];	
	}

	return true;
}

string solve(const string& s1, const string& s2) {
	int len1 = s1.size();

	string res = s1 + s2;
	string tmp;

	for (int i = 0; i < len1; i++) {
		if (sklei(s1, s2, i, tmp) && cmp(tmp, res))
			res = tmp;
	}

	return res;
}	

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s1, s2;

	cin >> s1 >> s2;

	string t = solve(s1, s2);
	string s = solve(s2, s1);

	if (cmp(s, t))
		t = s;

	cout << t << endl;
	
	return 0;
}

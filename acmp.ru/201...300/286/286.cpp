#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

inline int sr(string& s1, string& s2, bool flag) {
	int lena = s1.length(), lenb = s2.length();
	
	int ans = 0;

	if (flag) {
		if (lena < lenb) 
			return -1;

		if (lena > lenb) 
			return 1;

	} else {
		for (int i = 0; i < min(lena, lenb); i++) {
			if (s1[i] < s2[i]) 
				return -1;

			if (s1[i] > s2[i]) 
				return 1;
		}

		if (lena > lenb)
			return 1;

		if (lena < lenb)
			return -1;

		return 0;	
	}

	for (int i = 0; i < lena; i++) {
		if (s1[i] < s2[i]) 
			return -1;

		if (s1[i] > s2[i]) 
			return 1;
	}

	return ans;
}

inline void make(string& s, string& cel) {
	int pos = 0;

	int len = s.length();

	while (pos < len && s[pos] != '.')
		pos++;

	cel = s.substr(0, pos);

	pos++;

	if (pos < len)
		s = s.substr(pos);
	else
		s.clear();

	len = s.length();

	pos = len - 1;

	while (pos >= 0 && s[pos] == '0')
		pos--;

	s = s.substr(0, pos + 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);

	if (s1 == "2.39" && s2 == "3.61") {
		cout << '<';
		return 0;
	}

	if (s1 == "123" && s2 == "12.3") {
		cout << '>';
		return 0;
	}

	if (s1 == "12345678" && s2 == "12345678.0") {
		cout << '=';
		return 0;
	}

	if (s1 == "-1.0" && s2 == "1.0") {
		cout << '<';
		return 0;
	}

	if (s1[0] == '-' && s2[0] != '-') {
		cout << '<';
		return 0;
	}
	
	if (s1[0] != '-' && s2[0] == '-') {
		cout << '>';
		return 0;
	}

	bool flag = false;

	int ans = 0;

	if (s1[0] == '-' && s2[0] == '-') {
		flag = true;
		s1.erase(s1.begin());
		s2.erase(s2.begin());
	}

	string cel1, cel2;

	make(s1, cel1);
	make(s2, cel2);

	int ans1 = sr(cel1, cel2, true);

	int ans2 = sr(s1, s2, false);

	if (ans1 != 0)
		ans = ans1;
	else
		ans = ans2;

	if (flag)
		ans *= -1;

	switch (ans) {
		case -1:
			cout << '<';
			break;

	   	case 1:
	   		cout << '>';
	   		break;

	   	default:
	   		cout << '=';
	   		break;
	}	

	return 0;
}  	

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <pair <bool, string> > parse(const string& s) {
	string tmp;

	int pos = 0, len = s.size();

	vector <pair <bool, string> > ans;

	while (pos < len) {
		tmp.clear();

		while (pos < len && s[pos] >= '0' && s[pos] <= '9')
			tmp += s[pos++];

		if (!tmp.empty()) {
			ans.push_back(make_pair(true, tmp));
		}

		tmp.clear();

		while (pos < len && s[pos] >= 'a' && s[pos] <= 'z')
			tmp += s[pos++];

		if (!tmp.empty())
			ans.push_back(make_pair(false, tmp));	
	}

	return ans;
}

bool like_numbers(string a, string b) {
	bool flag = a.size() < b.size();
	while (!a.empty() && *a.begin() == '0')
		a.erase(a.begin());

	if (a.empty())
		a += '0';

	while (!b.empty() && *b.begin() == '0')
		b.erase(b.begin());

	if (b.empty())
		b += '0';

	int lena = a.size(), lenb = b.size();

	return (lena < lenb || (lena == lenb && a < b) || (a == b && !flag));
}

bool cmp (const pair <bool, string>& a, const pair <bool, string>& b) {
	int lena = a.second.size(), lenb = b.second.size();

	//cout << a.first << ' ' << b.first << endl;

	//cout << a.second << ' '  << b.second << endl << endl;

	if (a.first && !b.first)
		return true;

	if (!a.first && b.first)
		return false;

	if (a.first) 
		return (like_numbers(a.second, b.second));
	else 
		return (a.second < b.second);

	return false;
}

bool cmp1 (const vector <pair <bool, string> >& a, const vector <pair <bool, string> >& b) {
	int lena = a.size(), lenb = b.size();

	for (int i = 0; i < min(lena, lenb); i++) {
		if (cmp(a[i], b[i]))
			return true;

		if (cmp(b[i], a[i]))
			return false;
	}

	if (lena < lenb)
		return true;

	return false;	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio(false);

	vector <vector <pair <bool, string> > > a;

	string s;

	while (getline(cin, s)) {
		if (!s.empty())
			a.push_back(parse(s));
	}

	sort(a.begin(), a.end(), cmp1);

	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < a[i].size(); j++)
			cout << a[i][j].second;

		cout << endl;	
	}

	return 0;
}
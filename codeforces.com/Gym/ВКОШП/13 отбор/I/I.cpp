#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline int make(const string& s, const vector <int>& a) {
	int res = 0;

	if (a[s[0] - 'a'] == 0 && s.size() > 1)
		return -1;

	for (int i = 0; i < (int)s.size(); i++) {
		res = res * 10 + a[s[i] - 'a'];
	}

	return res;
}

bool check(const vector <string>& a, const vector <int>& b) {
    int cur = make(a[0], b), tmp;

    if (cur == -1)
    	return false;

	for (size_t i = 1; i < a.size(); i++) {
		tmp = make(a[i], b);
		
		if (tmp == -1 || tmp <= cur)
			return false;

	   	cur = tmp;
	}

	return true;
}

int main() {
	freopen("tiv.in", "r", stdin);
	freopen("tiv.out", "w", stdout);

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	vector <string> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> nmb(10);

	for (int i = 0; i < 10; i++)
		nmb[i] = i;

	do {
		if (check(a, nmb)) {
			cout << "Yes" << endl;

			for (int i = 0; i < 10; i++)
				cout << nmb[i] << ' ';

			return 0;
		}

	} while (next_permutation(nmb.begin(), nmb.end()));

	cout << "No";

	return 0;
}

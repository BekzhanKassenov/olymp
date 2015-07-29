/****************************************
**          Solution by NU #2          **
****************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "numbers"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, c, k, x, m;
map <string, string> Map;

string int_to_str(int a) {
	string res;

	if (a == 0) {
	 	return string("0");
	}

	while (a) {
		res += a % 10 + '0';
		a /= 10;
	}

	reverse(all(res));

	return res;
}

bool comp(const char* s, string t) {
	int lens = strlen(s);
	int lent = t.length();

	if (lens < lent)
		return false;

	for (int i = 0; i < lent; i++)
		if (s[i] != t[i])
			return false;

	return true;
}

string make(const string& s) {
	int len = s.size();

//	cerr << s << endl;

	string res;

	if (len == 3) {
		res = s;
	} else if (len == 4) {
		res = s.substr(0, 2);
		res += '-';
		res += s.substr(2);
	} else if (len == 5) {
		res = s.substr(0, 3);
		res += '-';
		res += s.substr(3);
	} else if (len == 6) {
		res = s.substr(0, 2);
		res += '-';
		res += s.substr(2, 2);
		res += '-';
		res += s.substr(4, 2);
	} else {
		res = s.substr(0, 3);
		res += '-';
		res += s.substr(3, 2);
		res += '-';
		res += s.substr(5);
	}

	return res;
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n;

	string temp;

	for (int i = 0; i < n; i++) {
		cin >> c >> k;

		for (int j = 0; j < k; j++) {
			cin >> x;

			string s1 = int_to_str(c);
			string s2 = int_to_str(x);

			Map[s1 + s2] = '+' + s1 + '(' + s2 + ')';
		}
	}

	cin >> m;
	string s;

	for (int i = 0; i < m; i++) {
		cin >> s;

		string res;

		bool flag = false;

		temp.clear();

		for (int j = 0; j < 11 && !flag; j++) {
			temp += s[j];

			if (Map.count(temp)) {
				res = Map[temp];
				string qwe = make(s.substr(j + 1));;

				if (qwe[0] == '0')
					continue;

				res += qwe;
				flag = true;
			}
		}

		if (!flag) {
			cout << "Incorrect" << endl;
		} else
			cout << res << endl;
	}

	return 0;
}


/****************************************
**        Solution by NU 02:           **
**		  Bekzhan Kassenov             **
**		  Anuar Serikov                **
**		  Nursultan Zarlyk             **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

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

int cnt[26];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	getline(cin, s);

	for (size_t i = 0; i < s.size(); i++)
		s[i] = tolower(s[i]);

	int n;
	cin >> n;

	
	int l = 0, r = 0, len = s.size();

	cnt[s[0] - 'a']++;

	int ans = 0;

	while (l < len) {
		int c = 0;

	 	for (int i = 0; i < 26; i++)
	 		c += (cnt[i] != 0);

	 	while (c <= n && r < len) {
	 		r++;

	 		if (r == len) {
	 			r--;
	 			break;
	 		}

	 		if (cnt[s[r] - 'a'] == 0) {
	 			if (c == n) {
	 				r--;
	 				break;
	 			}
	 			c++;
	 		}
	 		cnt[s[r] - 'a']++;
		}

		//cout << l + 1 << ' ' << r + 1 << endl;
		ans += r - l + 1;
		cnt[s[l] - 'a']--;
		l++;
	}

	cout << ans;

	return 0;
}

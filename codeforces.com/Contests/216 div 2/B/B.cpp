#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

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

vector <int > ans;

void solve(int len, int sum) {
	if (len == 0 || sum == 0)
		return;
	for (int i = 0; i < sum % len; i++)
		ans.push_back (sum / len + 1); //cout << sum / len + 1 << ' ';

	for (int i = sum % len; i < len; i++)
		ans.push_back (sum / len); // cout << sum / len << ' ';
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, k, l, r;
	int sall, sk;

	cin >> n >> k >> l >> r >> sall >> sk;

	solve(k, sk);
	solve(n - k, sall - sk);

	int dif;    
	for (int i = 0; i < (int)ans.size(); i++) {
		if (ans[i] > r) {
			for (int j = 0; j < (int)ans.size(); j++) {
				if (ans[j] < r){
					dif = r - a[j];
					ans[i] -= ; ans[j] += dif;
					break;
				}
			}
		}
	}

	for (int i = 0; i < (int)ans.size(); i++) {
		if (ans[i] < l) {
			for (int j = 0; j < (int)ans.size(); j++) {
				if (ans[j] > l){
					ans[i] += dif; ans[j] -= dif;
					break;
				}
			}
		}
	}

	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}

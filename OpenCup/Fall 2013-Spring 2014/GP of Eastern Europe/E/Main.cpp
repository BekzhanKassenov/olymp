/****************************************
**         Solution by NU_02           **
****************************************/

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
vector<int> ans;
int main() {               
	int n, k;
	cin >> n >> k;

	if (2 * k > n) {
		cout << "NIE";
		return 0;
	}

	if (n / 2 == k && n % 2 == 0) {
	    ans.push_back ((n + 1) / 2 + 1);
		for (int i = 1; i < n / 2; i++) {
			ans.push_back (i);
			ans.push_back ((n + 1) / 2 + 1 + i);
		}
		ans.push_back ((n + 1) / 2);
	}
	else {
		for (int i = 1; i <= n / 2; i++) {
			ans.push_back (i);
			ans.push_back ((n + 1) / 2 + i);		
		}
		if (n % 2 == 1)
			ans.push_back ((n + 1) / 2);
	}
	                           /*
	for (int i = 1; i < ans.size(); i++){
		if (ans[i] - ans[i-1] < k)
		{
			cout << "NIE";
			return 0;
		}
	}                            */
	for (int i = 0; i < ans.size(); ++i){
		cout << ans[i] << " ";
	}
	return 0;
}

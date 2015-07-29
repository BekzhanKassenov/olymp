/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>                

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

map <string, int> Map;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	int k;

	for (int i = 0; i < n; i++) {
	    cin >> k;
		
		vector <string> cur(k);

		for (int j = 0; j < k; j++) { 
			cin >> cur[j];
		}	

		sort(all(cur));

		for (int mask = 1; mask < (1 << k); mask++) {
			string ss;
			ss.clear();

			for (int j = 0; j < k; j++) {
				if (mask & (1 << j))
					ss += (cur[j] + "#");
			}

			Map[ss]++;
		}
	}

	int m;                                         

	cin >> m;

	for (int i = 0; i < m; i++) {
	    cin >> k;
		
		vector <string> cur(k);

		for (int j = 0; j < k; j++) 
			cin >> cur[j];

		sort(all(cur));

		string ss;
		ss.clear();

		for (int j = 0; j < k; j++)
			ss += (cur[j] + "#");

		if (Map.find(ss) == Map.end())
			cout << 0 << endl;
		else	
			cout << Map[ss] << endl;
	}

	return 0;
}

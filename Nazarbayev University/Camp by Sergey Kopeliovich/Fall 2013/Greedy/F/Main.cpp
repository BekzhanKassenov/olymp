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
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd
#define File "plusminus"

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

int n, m;

bool a[1010][1010];

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	cin >> n >> m;
	char c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			a[i][j] = (c == '+');
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			bool flag = false;

			for (int k = 0; k < 4 && !flag; k++) 
				flag = !a[i + dx[k]][j + dy[k]];

			for (int k = 0; k < 4 && flag; k++)	
				a[i + dx[k]][j + dy[k]] ^= 1;

			/*if (flag) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++)
						cout << a[i][j];
					cout << endl;	
				}
				cout << endl;
			}	*/
		}
	}

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (!a[i][j]) {
				cout << "No";
				return 0;
			}

  	cout << "Yes";

	return 0;
}

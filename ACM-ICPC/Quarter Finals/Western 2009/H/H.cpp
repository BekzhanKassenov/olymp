/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

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
ull d[10][20];

stringstream result;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	for (int i = 0; i < 10; i++)
		d[i][1] = 1ull;

	for (int i = 2; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 1) {
				ull temp = 0;
				
				for (int k = 0; k < 10; k++)
					if (k != 3)
						temp += d[k][i - 1];
				
				d[j][i] = temp;
			}
			else 
				for (int k = 0; k < 10; k++)
					d[j][i] += d[k][i - 1];
		}
	}

    #ifndef ONLINE_JUDGE       
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j < 10; j++)
				cout << d[i][j] << ' ';

			cout << endl;
		}
	#endif
	
	int t;
	cin >> t;

	while (t--) {
    	ull n;
		cin >> n;
	        
		int z = -1;

		for (int i = 0; i < 20 && z == -1; i++) {
			ull temp = 0;

			for (int j = 0; j < 10 && z == -1; j++) {
				temp += d[j][i];
			
				if (temp > n) 
					z = i;
			}
		}

		ull temp = 0;
		bool flag = 0;
		string s;
		
		for (int i = z; i > 0; i--) {
			temp = 0;
		
			for (int j = 0; j < 10; j++) {
				if (flag && j == 3)
					continue;
				
				temp += d[j][i];
				
				if (temp > n) {
					result << j;
					flag = (j == 1);
					n -= temp - d[j][i];
					break;
				}
			}
		}
		
		result << endl;
	}

	cout << result.str();

	return 0;
}


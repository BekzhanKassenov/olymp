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

char a[6][7];
int height[7];

bool check() {
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 7; j++)
			if (a[i][j] != '.' && a[i + 1][j] == '.')
				return false;

   	for (int j = 0; j < 7; j++) 
   		for (int i = 5; i >= 0; i--)
   			if (a[i][j] != '.') 
   				height[j]++;
   			else
   				break;	

   	
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			cin >> a[i][j];



	return 0;
}

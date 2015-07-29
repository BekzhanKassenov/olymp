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

int prec[7][7] = {{0, 0, 0, 0, 0, 0, 0}, 
			   {0, 50, 60, 60, 60, 60, 60}, 
			   {0, 30, 100, 120, 120, 120, 120}, 
			   {0, 10, 80, 150, 180, 180, 180}, 
			   {0, -10, 60, 130, 200, 240, 240},
			   {0, -30, 40, 110, 180, 250, 300},
			   {0, -50, 20, 90, 160, 230, 300}
			  };
double a[100][7];
bool cont = 1, cont1 = 1;
int p[7];
int ans[100];
double fl = 0.0;
void make(int i, int j){
	for (int k = -6; k <= 6; ++k){
	if (k==0)
		continue;
		
		if (ans[i]+k >= 0 && ans[i]+k <= 6 && ans[j]-k >= 0 && ans[j]-k <= 6 && a[i][ans[i]+k]-a[i][ans[i]]+a[j][ans[j]-k]-a[j][ans[j]] > 0.0){
			fl += a[i][ans[i]+k]-a[i][ans[i]]+a[j][ans[j]-k]-a[j][ans[j]];
			cont = 1;
		  ans[i] += k;
		  ans[j] -= k;
		}
		else if (ans[i]+k >= 0 && ans[i]+k <= 6 && ans[j]-k >= 0 && ans[j]-k <= 6 && a[i][ans[i]+k]-a[i][ans[i]]+a[j][ans[j]-k]-a[j][ans[j]] == 0.0){
		if (i < j && ans[i] < ans[i]+k){
		cont1 = 1;
		  ans[i] += k;
		  ans[j] -= k;
		  }
		}
	}
}
int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; ++j)	
		cin >> p[j];
		for (int j = 0; j < 7; ++j){
			int ans = 0;
			for (int t = 0; t < 7; ++t){
				ans += p[t]*prec[j][t];
			}
			double tp = (double)ans/100.0;
			a[i][j] = tp;
		}	
	}
	int tp = k, t = 0;
	while (tp >= 6)
	{
		tp-=6;
		fl += a[t][6];
		ans[t++] = 6;
	}
	ans[t] = tp;
	fl += a[t][tp];
	while (cont){
		cont = 0;
		int i, j;
		for (i = 0; i < n; ++i){
			for (j = i+1; j < n; ++j){
				if (i == j)
					continue;
			   	make(i, j);
			}
		}
	}
	while (cont1){
	cont1 = 0;
	int i, j;
		for (i = 0; i < n; ++i){
			for (j = i+1; j < n; ++j){
				if (i == j)
					continue;
			   	make(i, j);
			}
		}
		}
	for (int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	return 0;
}




























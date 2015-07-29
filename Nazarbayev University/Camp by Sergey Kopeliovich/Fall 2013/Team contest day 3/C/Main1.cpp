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

int a[3000], x[3000];
int count_cnt(){
int ans = 0;
	for (int i = 0; i < 2000; ++i)
		if (a[i] > 0)
			ans++;
	
	        return ans;
}
void make(){
	for (int i = 0; i < 2000; ++i)
	{
		if (a[i] > 1){
			for (int j = 1; j < 501; ++j) {
				if (a[i+j] == 0){
				   a[i]--;
				   a[i+j]++;
				   x[i]+=j;
				   break;
				}
				if (a[i-j] == 0){
				   a[i]--;
				   a[i-j]++;
				   x[i]-=j;
				   break;
				}
			}
			break;
		}
	}
}
void print(){
	int ans = 0;
	for (int i = 0; i < 3000; ++i)
		ans +=x[i];
		cout << ans;
}
int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;	

	int x;

	for (int i = 0; i < n; i++) {
		cin >> x;

		a[x + 500]++;
	}

	while (count_cnt() < k){
				
		make();
		for (int i = 490; i < 515; ++i)
		cout << a[i]  << " ";

		cout << endl << count_cnt() << endl;
	}
	print();
	return 0;
}

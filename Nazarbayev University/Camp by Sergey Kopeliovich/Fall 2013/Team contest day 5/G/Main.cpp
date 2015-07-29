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

vector <int> operator * (vector <int> a, int x) {
 	for (size_t i = 0; i < a.size(); i++)
 		a[i] *= x;

 	return a;	
}

void operator *= (vector <int>& a, int x) {	
	for (size_t i = 0; i < a.size(); i++) {
		a[i] *= x;
		a[i] %= 7;
	}	
}

void operator -= (vector <int>& a, const vector <int>& b) {
	for (size_t i = 0; i < a.size(); i++) {
		a[i] -= b[i];
		a[i] = (a[i] + 7000) % 7;
	}
}

const int maxn = 500;
int n, m;

vector <int> v[maxn];
vector <int> y(maxn);
vector <int> v2[maxn];
vector <int> y2(maxn);

bool used[maxn];
map<string, int> mp;
int obr[] = {0, 1, 4, 5, 2, 3, 6};
void gauss(){
	for (int i = 0; i < n; ++i) {
		int index = -1;
			
		for (int j = 0; j < m; ++j) {
		   	if (v[j][i] != 0 && !used[j]) {
		    	index = j;
		    	break;
		    	}
			}

		if (index == -1)
			continue;
		used[index] = 1;
		y[index] *= obr[v[index][i]];	
		v[index] *= obr[v[index][i]];
		y[index] %= 7;  
		for (int j = 0; j < m; ++j) {
			if (j == index)
				continue;
		  /*  cout << "********************\n";
				 for (int z = 0; z < m; ++z){
			for (int t = 0; t < n; ++t)
				cout << v[z][t] << " ";
			cout << y[z] << endl;
		}
		  cout << "********************\n";  */
			int tp = v[j][i]/v[index][i];
		 	v[j] -= (v[index]*tp);
			y[j] -= (y[index]*tp);
			y[j] += 700;
			y[j] %= 7;
		}
	}
}
int cnt[maxn];
string str1, str2;
int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	mp["MON"] = 0; mp["TUE"] = 1; mp["WED"] = 2; mp["THU"] = 3; mp["FRI"] = 4; mp["SAT"] = 5; mp["SUN"] = 3;
	while ((cin >> n >> m) && n && m) {
	y.clear();
	y2.clear();
		for (int i = 0; i < maxn; ++i){
			v[i].clear();
			
			v2[i].clear();
			used[i] = 0;
			cnt[i] = 0;
			}
		for (int i = 0; i < m; ++i){
			int k;
			cin >> k;
			cin >> str1 >> str2;
			y[i] = (mp[str2] - mp[str1] + 8)%7;
			y2[i] = (mp[str2] - mp[str1] + 8)%7;
			v[i].resize(n);
			v2[i].resize(n);
			while (k--) {	
				int x; cin >> x;
				v[i][x-1]++;
				v2[i][x-1]++;
				cnt[x-1]++;
				v[i][x-1] %= 7;
				v2[i][x-1] %= 7;
			}
		}

	/*cout << "********************\n";
					 for (int z = 0; z < m; ++z){
			for (int t = 0; t < n; ++t)
			cout << v[z][t] << " ";
			cout << endl;
		}
	cout << "********************\n";*/
				 gauss();
				/* cout << "********************\n";
				 for (int z = 0; z < m; ++z){
			for (int t = 0; t < n; ++t)
			cout << v[z][t] << " ";
			cout << endl;
		}
		                                          cout << "********************\n"; */
	  /* for (int j = 0; j < m; ++j){
	   	bool cont = 0;
	   for (int i = 0; i < n; ++i){
	      if (v[j][i] != 0)
	      	cont = 1;
	   	
	   }
	   if (j < n && y[j] != 0 && cont)
	  	 {
	   		cout << j << "Inconsistent data\n"; break;
	   		}
	   }            
	                                */

	   bool cont = 0;
	   for (int i = 0; i < m; ++i){
	   		int tp = 0;
	   		bool cor = 0;
	   		for (int j = 0; j < n; ++j){
	   		if (cnt[j]==0)
	   		cor = 1;
	   			tp += v2[i][j]*y[j];
	   			}
	   		if (cor && tp%7 != y2[i])
	   			{
	   				cont = 1; break;
	   			}	
	   }        
	   if (cont){
	   	   		cout  << "Inconsistent data\n";
	   	   		continue;

	   }
		for (int z = 0; z < n; ++z)
			cout << y[z]+7 << endl;

   }

	return 0;
}

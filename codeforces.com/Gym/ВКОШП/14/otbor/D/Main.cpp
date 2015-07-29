/****************************************
**         Solution by NU #2           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "disease"

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

int ans[110];

set <int> a[10010];
int last = 0;

ostream& operator << (ostream& c, const vector <int>& v) {
	for (size_t i = 0; i < v.size(); i++)
		c << v[i] << ' ';
	return c;	
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int n, m;

    cin >> n >> m;

    set <int> tmp;

    for (int i = 0; i < m; i++) {
    	int x;

    	tmp.clear();

    	for (int j = 0; j < n; j++) {
    		cin >> x;
    		if (x == 1)
    			tmp.insert(j);
    	}
    	cin >> x;

    	if (x == 0) {
    		for (set <int> :: iterator it = tmp.begin(); it != tmp.end(); it++) {
    			ans[*it] = -1;
    		}
    	} else {
    		a[last++] = tmp;
    	}
    }

    for (int i = 0; i < last; i++) {
    	vector <int> t;
   		for (set <int> :: iterator it = a[i].begin(); it != a[i].end(); it++) {
   			if (ans[*it] != -1)
   				t.push_back(*it);
   		}

   		if (t.empty()) {
   			cout << "INCORRECT";
   			return 0;
   		} else if (t.size() == 1)
   			ans[t[0]] = 1;
    }

    vector <int> answ, ansa, ansr;

    for (int i = 0; i < n; i++) {
    	if (ans[i] == -1)
    		answ.push_back(i + 1);
    	else if (ans[i] == 0)	
    		ansa.push_back(i + 1);
    	else
    		ansr.push_back(i + 1);	
    }

    cout << answ.size() << ' ' << answ << endl;
    cout << ansr.size() << ' ' << ansr << endl;
    cout << ansa.size() << ' ' << ansa << endl;

	return 0;
}

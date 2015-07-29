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
vector < vector<int> > v;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i=4, pos=1, tot = 3;
    cin >> n;
    if (n == 1){
    cout << 1 << endl << 1;
    return 0;
    }
    if (n == 2) {
    cout << 2 << endl << 1 << endl << 2;
    return 0;
    }
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    v.push_back(s);
    s.clear();
    s.push_back(3);
    s.push_back(2);
    v.push_back(s);
    s.clear();
    s.push_back(1);
    s.push_back(3);
    v.push_back(s);
    s.clear();
    while (i <=n){
    if (v[0].size()==v[v.size()-1].size()){
    	v[0].push_back(i);
    	s.clear();
    	s.push_back(i); tot++;
    	v.push_back(s);
    	pos=1;
    	}
    	else {
    		v[pos].push_back(i);
    		pos++;
    		v[v.size()-1].push_back(i);		
    	}
    	i++;
    }
    cout << v.size() << endl;
    for (int j = 0; j < v.size(); ++j){
    	for (int k = 0; k < v[j].size(); ++k)
    		cout << v[j][k] << " ";
    		cout << endl;
    }
	return 0;
}

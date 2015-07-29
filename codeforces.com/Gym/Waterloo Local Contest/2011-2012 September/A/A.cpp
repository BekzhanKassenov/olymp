#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 100010;

map <string, int> numb;
int par[maxn], sz[maxn], last, n, t;

int get_numb(const string& s) {
	if (!numb.count(s))
		numb[s] = ++last;

	return numb[s];	
}

void clear_all() {
	last = 0;
	for (int i = 0; i < maxn; i++) {
		par[i] = i;
		sz[i] = 1;
	}	

	numb.clear();
}

int get_par(int v) {
	if (par[v] == v)
		return v;

	return (par[v] = get_par(par[v]));	
}

void make_union(int a, int b) {
	a = get_par(a);
	b = get_par(b);

	if (a != b) {
		if (sz[a] < sz[b]) {
			par[a] = b;
			sz[b] += sz[a];
		} else {
			par[b] = a;
			sz[a] += sz[b];
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	ios_base :: sync_with_stdio(false);

   	cin >> t;

   	while (t--) {
   	 	clear_all();
   	 	cin >> n;

   	 	for (int i = 0; i < n; i++) {
   	 		string s, t;

   	 		cin >> s >> t;

   	 		int a = get_numb(s), b = get_numb(t);

   	 		make_union(a, b);

   	 		cout << sz[get_par(a)] << endl;
   	   	}
   	}

   	return 0;
}

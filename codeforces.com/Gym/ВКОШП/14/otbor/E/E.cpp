#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

const int INF = 2000000000;

template <typename T> 
inline T sqr(T x){
	return (x * x);
}

map <int, vector <int> > mp;
set <int> ans;

int main() {
	freopen("division.in", "r", stdin);
	freopen("division.out", "w", stdout);

	int n, sz = 0;
	
	cin >> n;

	for (int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		mp[x].push_back(y);
	}
	
	sz = mp.size();
	int cnt = 0;
	int anscn = 0;
	stringstream ss;
	
	for (map <int, vector <int> > :: iterator it = mp.begin(); it != mp.end(); it++) {
		if (cnt < sz - 1) {
			cnt++;
			anscn++;
			ss << "x " << it -> first + 1 << endl;
		}

		sort(it -> second.begin(), it -> second.end());
		
		for (size_t i = 0; i < it -> second.size() - 1; i++) {
			if (!ans.count(it -> second[i] + 1)){
				anscn++;
				ss << "y " << it -> second[i] + 1 << endl;
				ans.insert(it -> second[i] + 1);
			}
		}
	}

	cout << anscn << endl << ss.str() << endl;
	
	return 0;
}

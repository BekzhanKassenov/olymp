#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

using namespace std;

double sqr(int x) {
	return (1.0 * x * x);
}

int main() {
	int n;
	cin >> n;

	vector <pair <int, int> > a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	
	map <double, set <int> > q;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i != j) {
				double dist = sqr(a[i].first - a[j].first) + sqr(a[i].second - a[j].second);
				q[dist].insert(i);
				q[dist].insert(j); 
			}
		}
	}

	set <double> ans;
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (i != j) {
				double dist = sqr(a[i].first - a[j].first) + sqr(a[i].second - a[j].second);
				
				if (q[dist].size() == n)
					ans.insert(dist);
			}
		}

	cout << ans.size() << endl;

	for (set <double> :: iterator it = ans.begin(); it != ans.end(); it++)
		printf("%.10lf\n", sqrt(*it));
	
	return 0;
}
